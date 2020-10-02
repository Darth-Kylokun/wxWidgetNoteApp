#include <array>
#include "wx/wx.h"
#include "wx/richtext/richtextctrl.h"
#pragma once

class cMain : public wxFrame
{
public:
	cMain();

	wxRichTextCtrl* richTextCtrl = nullptr;

	std::array<wxFont, 3> fonts;

	wxDECLARE_EVENT_TABLE();
};

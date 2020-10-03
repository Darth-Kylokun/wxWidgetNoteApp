#include <array>
#include "wx/wx.h"
#include "wx/richtext/richtextctrl.h"
#include "wx/filedlg.h"
#include "wx/wfstream.h"
#pragma once

class cMain : public wxFrame
{
public:
	cMain();

	void load(wxCommandEvent& evt);
	void save(wxCommandEvent& evt);
	void exit(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
private:
	std::array<wxFont, 3> fonts;
	wxRichTextCtrl* richTextCtrl = nullptr;
	wxMenuBar* menuBar = nullptr;
	bool firstSaveFlag = true;
};

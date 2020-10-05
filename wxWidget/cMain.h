#include <array>
#include <memory>
#include <cstdint>
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
	void fontIncrease(wxCommandEvent& evt);
	void fontDecrease(wxCommandEvent& evt);
	void changeFontFamily(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
private:
	std::array<wxFont, 3> fonts;
	wxRichTextCtrl* richTextCtrl = nullptr;
	wxMenuBar* menuBar = nullptr;
	bool firstSaveFlag = true;
	wxString fileLoc;
	uint_least32_t fontSize = 12;
	wxFontFamily fontFamily = wxFONTFAMILY_ROMAN;
	wxFontStyle fontStyle = wxFONTSTYLE_NORMAL;
	wxFontWeight fontWeight = wxFONTWEIGHT_NORMAL;
};

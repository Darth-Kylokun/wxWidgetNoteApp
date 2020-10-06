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
	void keyMacros(wxCommandEvent& key);

	wxDECLARE_EVENT_TABLE();
private:
	wxTextCtrl* textCtrl = nullptr;
	wxMenuBar* menuBar = nullptr;
	struct
	{
		bool firstSaveFlag = true;
		bool saved = true;
	} flags;
	wxString fileLoc;
	struct
	{
		uint_least32_t size = 12;
		wxFontFamily family = wxFONTFAMILY_ROMAN;
		wxFontStyle style = wxFONTSTYLE_NORMAL;
		wxFontWeight weight = wxFONTWEIGHT_NORMAL;
	} font;

	void m_save();
	void m_load();
};
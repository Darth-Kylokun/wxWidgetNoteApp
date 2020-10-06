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
	void unsave(wxCommandEvent& key);
	
	void m_fontIncrease();
	void m_fontDecrease();
	void m_save();
	void m_load();

	wxTextCtrl* textCtrl = nullptr;

	wxDECLARE_EVENT_TABLE();
private:
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
};
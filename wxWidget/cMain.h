#include "wx/wx.h"
#pragma once

class cMain : public wxFrame
{
public:
	cMain();

	wxButton* m_btn = nullptr;
	wxTextCtrl* m_txt = nullptr;
	wxListBox* m_list = nullptr;

	void OnButtonClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

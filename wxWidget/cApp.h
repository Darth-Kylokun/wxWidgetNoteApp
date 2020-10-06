#include "wx/wx.h"
#include "cMain.h"
#pragma once

class cApp : public wxApp
{
public:
	cApp();

	void macroHandler(wxKeyEvent& key);

	virtual bool OnInit();
private:
	cMain* m_frame = new cMain();
	wxDECLARE_EVENT_TABLE();
};

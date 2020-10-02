#include "wx/wx.h"
#include "cMain.h"
#pragma once

class cApp : public wxApp
{
public:
	cApp();

	virtual bool OnInit();
private:
	cMain* m_frame = nullptr;
};

#include "wx/wx.h"

class cMain : public wxFrame
{
public:
	cMain()
		: wxFrame(nullptr, wxID_ANY, "Hello, World!") {}
};

class cApp : public wxApp
{
public:
	cApp() {};

	virtual bool OnInit()
	{
		m_frame = new cMain();
		m_frame->Show();

		return true;
	}
private:
	cMain* m_frame = nullptr;
};

wxIMPLEMENT_APP(cApp);
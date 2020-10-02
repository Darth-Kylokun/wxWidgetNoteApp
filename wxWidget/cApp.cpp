#include "cApp.h"

wxIMPLEMENT_APP(cApp);

cApp::cApp() = default;

bool cApp::OnInit()
{
	m_frame = new cMain();
	m_frame->Show();

	return true;
}
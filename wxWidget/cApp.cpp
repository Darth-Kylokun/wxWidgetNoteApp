#include "cApp.h"

wxBEGIN_EVENT_TABLE(cApp, wxApp)
	EVT_CHAR_HOOK(macroHandler)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(cApp);

cApp::cApp() = default;

void cApp::macroHandler(wxKeyEvent & key)
{
	if (key.ControlDown())
		switch (key.GetUnicodeKey())
		{
		case 'S':
			m_frame->m_save();
			return;
		case 'L':
			m_frame->m_load();
			return;
		case '=':
			m_frame->m_fontIncrease();
			return;
		case '-':
			m_frame->m_fontDecrease();
			return;
		default:
			return;
		}
	key.DoAllowNextEvent();
}

bool cApp::OnInit()
{
	m_frame->Show();

	return true;
}
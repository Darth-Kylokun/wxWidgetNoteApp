#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	
wxEND_EVENT_TABLE()

cMain::cMain()
	: wxFrame{ nullptr, wxID_ANY, "Totally not a Notepad rip off", wxPoint(30, 30), wxSize(800, 600) },
	richTextCtrl{ new wxRichTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxVSCROLL | wxHSCROLL | wxBORDER_DEFAULT | wxWANTS_CHARS) },
	fonts{ wxFont(12, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL), wxFont(12, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD), wxFont(12, wxFONTFAMILY_ROMAN, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL) }
{
	//fonts[0] is normal
	//fonts[1] is bold
	//fonts[2] is italic
	richTextCtrl->SetFont(fonts[0]);
}
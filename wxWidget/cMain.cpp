#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_MENU(10001, load)
	EVT_MENU(10002, save)
	EVT_MENU(10003, exit)
wxEND_EVENT_TABLE()

//fonts[0] is normal
//fonts[1] is bold
//fonts[2] is italic

cMain::cMain()
	: wxFrame{ nullptr, wxID_ANY, "Totally not a Notepad rip off", wxPoint(30, 30), wxSize(800, 600) },
	  richTextCtrl{ new wxRichTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxVSCROLL | wxHSCROLL | wxBORDER_DEFAULT | wxWANTS_CHARS) },
	  fonts{ wxFont(12, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL), wxFont(12, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD), wxFont(12, wxFONTFAMILY_ROMAN, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL) },
	  menuBar{ new wxMenuBar() }
{
	richTextCtrl->SetFont(fonts[0]);

	wxMenu* menu = new wxMenu();
	menu->Append(10001, "Open");
	menu->Append(10002, "Save");
	menu->Append(10003, "Exit");

	menuBar->Append(menu, "File");

	this->SetMenuBar(menuBar);
}

void cMain::load(wxCommandEvent& evt)
{
	wxFileDialog* openFileDialog = new wxFileDialog(this, "Open File:");
	if (openFileDialog->ShowModal() == wxID_CANCEL)
		return;
	
	richTextCtrl->LoadFile(openFileDialog->GetPath());
}

void cMain::save(wxCommandEvent& evt)
{
	if (firstSaveFlag)
	{
		wxFileDialog* saveFileDialog = new wxFileDialog(this, "Save File: ");
		if (saveFileDialog->ShowModal() == wxID_CANCEL)
			return;

		wxFileOutputStream* stream = new wxFileOutputStream(saveFileDialog->GetPath());
		if (!stream->IsOk())
		{
			wxLogError("Cannont save file in '%s'", saveFileDialog->GetPath());
			return;
		}
	}

}

void cMain::exit(wxCommandEvent& evt)
{
	this->Close();
	evt.Skip();
}
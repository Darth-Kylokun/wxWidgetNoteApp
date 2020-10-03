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
	: wxFrame{ nullptr, wxID_ANY, "Totally Not A Notepad Rip Off", wxPoint(30, 30), wxSize(800, 600) },
	  richTextCtrl{ new wxRichTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxVSCROLL | wxHSCROLL | wxBORDER_DEFAULT | wxWANTS_CHARS) },
	  fonts{ wxFont(12, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL), wxFont(12, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD), wxFont(12, wxFONTFAMILY_ROMAN, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL) },
	  menuBar{ new wxMenuBar() }
{
	richTextCtrl->SetFont(fonts[0]);
	
	wxMenu* fileMenu = new wxMenu();
	fileMenu->Append(10001, "Load");
	fileMenu->Append(10002, "Save");
	fileMenu->Append(10003, "Exit");

	menuBar->Append(fileMenu, "File");

	this->SetMenuBar(menuBar);
}

void cMain::load(wxCommandEvent& evt)
{
	std::unique_ptr<wxFileDialog> openFileDialog = std::make_unique<wxFileDialog>(this, "OpenFile:");
	if (openFileDialog.get()->ShowModal() == wxID_CANCEL)
		return;

	wxString lastThree = "";
	for (int i = 1; i <= 3; ++i)
		lastThree.append(openFileDialog.get()->GetPath()[openFileDialog.get()->GetPath().size() - i]);

	if (lastThree != "txt")
		return;

	fileLoc = openFileDialog.get()->GetPath();
	firstSaveFlag = false;
	richTextCtrl->LoadFile(openFileDialog.get()->GetPath());

	wxString newTitle = "Totally Not A Notepad Rip Off (";
	newTitle.append(openFileDialog.get()->GetPath());
	newTitle.append(")");
	this->SetTitle(newTitle);

	return;
}

void cMain::save(wxCommandEvent& evt)
{
	if (firstSaveFlag)
	{
		std::unique_ptr<wxFileDialog> saveFileDialog = std::make_unique<wxFileDialog>(this, "Save File:");
		if (saveFileDialog.get()->ShowModal() == wxID_CANCEL)
			return;

		richTextCtrl->SaveFile(saveFileDialog.get()->GetPath());

		firstSaveFlag = false;
		fileLoc = saveFileDialog.get()->GetPath();

		wxString newTitle = "Totally Not A Notepad Rip Off (";
		newTitle.append(fileLoc);
		newTitle.append(")");
		this->SetTitle(newTitle);

		return;
	}
	richTextCtrl->SaveFile(fileLoc);
	return;
}

void cMain::exit(wxCommandEvent& evt)
{
	this->Close();
	return;
}
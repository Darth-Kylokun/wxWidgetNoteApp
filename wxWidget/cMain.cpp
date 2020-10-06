#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_MENU(10001, load)
	EVT_MENU(10002, save)
	EVT_MENU(10003, exit)
	EVT_MENU(10004, fontIncrease)
	EVT_MENU(10005, fontDecrease)
	EVT_TEXT(10006, unsave)
wxEND_EVENT_TABLE()

cMain::cMain()
	: wxFrame{ nullptr, wxID_ANY, "Totally Not A Notepad Rip Off", wxPoint(30, 30), wxSize(800, 600) },
	  textCtrl{ new wxTextCtrl(this, 10006, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxVSCROLL | wxHSCROLL | wxBORDER_SUNKEN  | wxTE_MULTILINE) },
	  menuBar{ new wxMenuBar() }
{
	textCtrl->SetFont(wxFont(font.size, font.family, font.style, font.weight));

	wxMenu* fileMenu = new wxMenu();
	fileMenu->Append(10001, "Load");
	fileMenu->Append(10002, "Save");
	fileMenu->Append(10003, "Exit");

	wxMenu* editMenu = new wxMenu();
	editMenu->Append(10004, "Increase Font");
	editMenu->Append(10005, "Decrease Font");

	menuBar->Append(fileMenu, "File");
	menuBar->Append(editMenu, "Edit");

	this->SetMenuBar(menuBar);
}

void cMain::load(wxCommandEvent& evt)
{
	m_load();
	evt.Skip();
}

void cMain::save(wxCommandEvent& evt)
{
	m_save();
	evt.Skip();
}

void cMain::fontIncrease(wxCommandEvent& evt)
{
	font.size += 1;
	textCtrl->SetFont(wxFont(font.size, font.family, font.style, font.weight));
	evt.Skip();
}

void cMain::fontDecrease(wxCommandEvent& evt)
{
	if (font.size != 1)
	{
		font.size -= 1;
		textCtrl->SetFont(wxFont(font.size, font.family, font.style, font.weight));
	}
	evt.Skip();
}

void cMain::unsave(wxCommandEvent& evt)
{
	if (flags.saved)
	{
		this->SetTitle(this->GetTitle() + "*");
		flags.saved = false;
	}
}

void cMain::m_save()
{
	if (!flags.saved)
	{
		if (flags.firstSaveFlag)
		{
			std::unique_ptr<wxFileDialog> saveFileDialog = std::make_unique<wxFileDialog>(this, "Save File:");
			if (saveFileDialog.get()->ShowModal() == wxID_CANCEL)
				return;

			textCtrl->SaveFile(saveFileDialog.get()->GetPath());

			flags.firstSaveFlag = false;
			flags.saved = true;
			fileLoc = saveFileDialog.get()->GetPath();

			this->SetTitle(this->GetTitle().RemoveLast() + (" (" + saveFileDialog.get()->GetPath() + ")"));

			return;
		}
		flags.saved = true;
		this->SetTitle(this->GetTitle().RemoveLast());
		textCtrl->SaveFile(fileLoc);
		return;
	}
}

void cMain::m_load()
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
	flags.firstSaveFlag = false;
	textCtrl->LoadFile(openFileDialog.get()->GetPath());

	this->SetTitle("Totally Not A Notepad Rip Off (" + openFileDialog.get()->GetPath() + ")");
	flags.saved = true;
	return;
}

void cMain::exit(wxCommandEvent& evt)
{
	this->Close();
	return;
}
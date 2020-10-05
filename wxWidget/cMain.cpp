#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_MENU(10001, load)
	EVT_MENU(10002, save)
	EVT_MENU(10003, exit)
	EVT_MENU(10004, fontIncrease)
	EVT_MENU(10005, fontDecrease)
	EVT_MENU(10006, changeFontFamily)
wxEND_EVENT_TABLE()

//fonts[0] is normal
//fonts[1] is bold
//fonts[2] is italic

cMain::cMain()
	: wxFrame{ nullptr, wxID_ANY, "Totally Not A Notepad Rip Off", wxPoint(30, 30), wxSize(800, 600) },
	  richTextCtrl{ new wxRichTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxVSCROLL | wxHSCROLL | wxBORDER_DEFAULT | wxWANTS_CHARS) },
	  menuBar{ new wxMenuBar() }
{
	richTextCtrl->SetFont(wxFont(fontSize, fontFamily, fontStyle, fontWeight));
	
	wxMenu* fileMenu = new wxMenu();
	fileMenu->Append(10001, "Load");
	fileMenu->Append(10002, "Save");
	fileMenu->Append(10003, "Exit");

	wxMenu* editMenu = new wxMenu();
	editMenu->Append(10004, "Increase Font");
	editMenu->Append(10005, "Decrease Font");
	editMenu->Append(10006, "Change Font");

	menuBar->Append(fileMenu, "File");
	menuBar->Append(editMenu, "Edit");

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

void cMain::fontIncrease(wxCommandEvent& evt)
{
	fontSize += 1;
	richTextCtrl->SetFont(wxFont(fontSize, fontFamily, fontStyle, fontWeight));
}

void cMain::fontDecrease(wxCommandEvent& evt)
{
	if (fontSize != 1)
	{
		fontSize -= 1;
		richTextCtrl->SetFont(wxFont(fontSize, fontFamily, fontStyle, fontWeight));
	}
}

void cMain::changeFontFamily(wxCommandEvent& evt)
{

}

void cMain::exit(wxCommandEvent& evt)
{
	this->Close();
	return;
}
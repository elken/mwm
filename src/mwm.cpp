#include "mwm.h"

BEGIN_EVENT_TABLE(Mwm, wxFrame)
EVT_MENU(wxID_OPEN, Mwm::OnOpen)
EVT_MENU(wxID_SAVE, Mwm::OnSave)
EVT_MENU(wxID_SAVEAS, Mwm::OnSaveAs)
EVT_MENU(wxID_EXIT, Mwm::OnExit)
EVT_MENU(wxID_ABOUT, Mwm::OnAbout)
END_EVENT_TABLE()

Mwm::Mwm(const wxString& title, int xpos, int ypos, int w, int h) 
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(w, h))
{
	CreateBars(m_pMenuBar, m_pFileMenu, m_pHelpMenu);
}

void Mwm::CreateBars(wxMenuBar *m_pMenuBar, wxMenu *m_pFileMenu, wxMenu *m_pHelpMenu)
{
	// Define & allocate menubar
	m_pMenuBar = new wxMenuBar();

	// File menu create & initialize
	m_pFileMenu = new wxMenu();
	m_pFileMenu->Append(wxID_OPEN, _T("&Open (ROM)"), _T("Open a compatible ROM"));
	m_pFileMenu->Append(wxID_SAVE, _T("&Save (ROM)"), _T("Save the contents"));
	m_pFileMenu->Append(wxID_SAVEAS, _T("&Save As (ROM)"), _T("Save the contents to a new ROM"));
	m_pFileMenu->AppendSeparator();
	m_pFileMenu->Append(wxID_EXIT, _T("&Quit"), _T("Quit the application"));
	m_pMenuBar->Append(m_pFileMenu, _T("&File"));

	// About/help menu
	m_pHelpMenu = new wxMenu();
	m_pHelpMenu->Append(wxID_ABOUT, _T("&About"), _T("Help information about the program"));
	m_pMenuBar->Append(m_pHelpMenu, _T("&Help"));

	// Create menubar & statusbar
	SetMenuBar(m_pMenuBar);
	CreateStatusBar(3);
}

void Mwm::OnOpen(wxCommandEvent &event)
{
	wxFileDialog *OpenDialog = new wxFileDialog(this, _T("Choose a file"), _(""), _(""), _("*.*"), wxFD_OPEN);
	if (OpenDialog->ShowModal() == wxID_OK)
	{
		wxString path = OpenDialog->GetPath();
		path.IsAscii() ?
			SetStatusText(_T("Loaded")) :
			SetStatusText(_T("Load Failed"));
	}
	OpenDialog->Close(); // Or OpenDialog->Destroy() ?
}

void Mwm::OnSave(wxCommandEvent &event)
{
	wxFileDialog *SaveDialog = new wxFileDialog(this, _T("Choose a file"), _(""), _(""), _("*.*"), wxFD_SAVE);
	if (SaveDialog->ShowModal() == wxID_OK)
	{
		wxString path = SaveDialog->GetPath();
		path.IsAscii() ?
			SetStatusText(_T("Saved")) :
			SetStatusText(_T("Save Failed"));
	}
	SaveDialog->Close();
}

void Mwm::OnSaveAs(wxCommandEvent &event)
{
	wxFileDialog *SaveAsDialog = new wxFileDialog(this, _T("Choose a file"), _(""), _(""), _("*.*"), wxFD_SAVE);
	if (SaveAsDialog->ShowModal() == wxID_OK)
	{
		wxString path = SaveAsDialog->GetPath();
		path.IsAscii() ?
			SetStatusText(_T("Saved")) :
			SetStatusText(_T("Save Failed"));
	}
	SaveAsDialog->Close();
}

void Mwm::OnExit(wxCommandEvent &event)
{
	Close(false);
}

void Mwm::OnAbout(wxCommandEvent &event)
{
	wxLogMessage(_T("TODO: Create an about window"));
}


#ifndef MWM_H
#define MWM_H
#include <wx/wx.h>

class Mwm 
	: public wxFrame
{
	wxMenuBar *m_pMenuBar;
	wxMenu *m_pFileMenu;
	wxMenu *m_pHelpMenu;

public:
	Mwm(const wxString& title, int xpos, int ypos, int w, int h);
	void CreateBars(wxMenuBar *m_pMenuBar, wxMenu *m_pFileMenu, wxMenu *m_pHelpMenu);

	void OnOpen(wxCommandEvent &event);
	void OnSave(wxCommandEvent &event);
	void OnSaveAs(wxCommandEvent &event);
	void OnExit(wxCommandEvent &event);
	void OnAbout(wxCommandEvent &event);
	void OnSize(wxSizeEvent &event);

protected:
	DECLARE_EVENT_TABLE()
};

#endif //MWM_H
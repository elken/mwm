#ifndef PANEL_H
#define PANEL_H
#include <wx/wx.h>
#include <wx/sizer.h>

class wxImagePanel 
	: public wxPanel
{
	wxImage image;
	int w, h;
public:
	wxImagePanel(wxFrame *parent, wxString file, wxBitmapType format);

	void paintEvent(wxPaintEvent &evt);

	void render(wxDC &dc);

protected:
	DECLARE_EVENT_TABLE()
};

#endif //PANEL_H
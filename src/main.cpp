#include "main.h"
#include "mwm.h"
#include <string>


IMPLEMENT_APP(Main)

bool Main::OnInit()
{
	wxInitAllImageHandlers();
	wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	Mwm *mwm = new Mwm(wxT("Metroid: Warp Mission"), wxALIGN_CENTER_HORIZONTAL, wxALIGN_CENTER_VERTICAL, 1024, 768);

	drawPane = new wxImagePanel(mwm, wxT("res/full.png"), wxBITMAP_TYPE_PNG);
	sizer->Add(drawPane, 1, wxEXPAND);
	mwm->SetSizer(sizer);

	mwm->Show(true);

	return true;
}
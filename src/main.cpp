#include "main.h"
#include "mwm.h"

IMPLEMENT_APP(Main)

bool Main::OnInit()
{
	Mwm *mwm = new Mwm(wxT("Metroid: Warp Mission"));
	mwm->Show(true);

	return true;
}
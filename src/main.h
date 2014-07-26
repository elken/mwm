#ifndef MAIN_H
#define MAIN_H
#include <wx/wx.h>
#include "panel.h"

class Main 
	: public wxApp
{
	wxFrame *frame;
	wxImagePanel *drawPane;
public:
	virtual bool OnInit();
};

#endif //MAIN_H
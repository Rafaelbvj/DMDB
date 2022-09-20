#pragma once
#include <wx/wx.h>
#include "MainForm.h"

class DMBD : public wxApp {
private:
	MainForm* mainform = nullptr;
	
public:
	DMBD();
	~DMBD();
	bool OnInit();
	
};

 
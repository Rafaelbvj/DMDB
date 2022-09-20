#pragma once
#include "DMBD.h"

wxIMPLEMENT_APP(DMBD);

DMBD::DMBD() {


}
DMBD::~DMBD() {
	
}
bool DMBD::OnInit() {
	
	mainform = new MainForm();
	
	mainform->Show();
	
	return true;
}

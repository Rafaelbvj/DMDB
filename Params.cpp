#include "Params.h"
Params* Params::params = nullptr;
Params::Params(wxWindow* pai) : wxScrolledWindow(pai, wxID_ANY, wxPoint(0, 0)) {
	
	bs = new wxBoxSizer(wxVERTICAL);
	rp = new RetanguloParams(this);
	bs->Add(rp, 1, wxEXPAND , 0);
	SetSizer(bs);
	SetScrollbar(wxVERTICAL, 0, 1, 10);
	SetScrollbar(wxHORIZONTAL, 0, 1, 10);
	SetScrollRate(10, 10);
	
}
Params* Params::getInstance(wxWindow* pai) {
	if (params == nullptr) {
		params = new Params(pai);
	}
	return params;
}
void Params::update() {
	CalcParams* params = CalcParams::getInstance();
	bs->Clear(true);
	switch (params->var.tipo_select) {
	case 0:
		rp = new RetanguloParams(this);
		bs->Add(rp, 1, wxEXPAND ,0);
		
		break;
	case 1:
		rp2 = new Retangulo2Params(this);
		bs->Add(rp2, 1, wxEXPAND ,0);
		break;
	}
	bs->Layout();
	GetParent()->Layout();
}
Params::~Params() {

}
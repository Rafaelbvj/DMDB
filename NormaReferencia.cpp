#include "NormaReferencia.h"
NormaReferencia::NormaReferencia(wxWindow *pai) : wxDialog(pai,wxID_ANY,"Norma de Referência",wxDefaultPosition,wxSize(200,200)){
	
	wxBoxSizer* bs = new wxBoxSizer(wxVERTICAL);
	wxStaticBoxSizer* sb = new wxStaticBoxSizer(wxVERTICAL,this,"Método de cálculo");
	params = CalcParams::getInstance();
	nbr22 = new wxRadioButton(this, 10013, "NBR 7190/22");
	nbr97 = new wxRadioButton(this, 10012, "NBR 7190/97");
	nbr82 = new wxRadioButton(this, 10011, "NBR 7190/82");

	nbr82->SetValue(params->var.met_calc & 0xFF0000);
	nbr97->SetValue(params->var.met_calc & 0xFF00);
	nbr22->SetValue(params->var.met_calc & 0xFF);
	nbr82->Bind(wxEVT_RADIOBUTTON, &NormaReferencia::salvar, this);
	nbr97->Bind(wxEVT_RADIOBUTTON, &NormaReferencia::salvar, this);
	nbr22->Bind(wxEVT_RADIOBUTTON, &NormaReferencia::salvar, this);
	sb->AddSpacer(20);
	sb->Add(nbr22);
	sb->AddSpacer(10);
	sb->Add(nbr97);
	sb->AddSpacer(10);
	sb->Add(nbr82);
	sb->AddSpacer(10);
	bs->Add(sb,1,wxEXPAND|wxALL,10);

	SetSizer(bs);

}
void NormaReferencia::salvar(wxCommandEvent& evt) {
	params->var.met_calc = 0;
	params->var.met_calc |= (nbr82->GetValue() ? 0xFF000 : 0) | (nbr97->GetValue() ? 0xFF00 : 0) | (nbr22->GetValue() ? 0xFF : 0);
}
NormaReferencia::~NormaReferencia() {

}
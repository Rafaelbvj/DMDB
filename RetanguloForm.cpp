#include "RetanguloForm.h"
RetanguloForm::RetanguloForm(wxWindow *pai): wxPanel(pai,wxID_ANY,wxDefaultPosition) {
	CalcParams* params = CalcParams::getInstance();
	//Desenho ilustrativo
	wxBitmap* ret_bmp = new wxBitmap("res\\secao_ret.bmp", wxBITMAP_TYPE_BMP);
	wxMask* ret_mask = new wxMask(*ret_bmp, wxColour(0xFFFFFFFF));
	ret_bmp->SetMask(ret_mask);
	bs_ret = new wxBoxSizer(wxVERTICAL);
	wxStaticBitmap* ret_sb = new wxStaticBitmap(this, wxID_ANY, wxBitmapBundle(*ret_bmp));
	bs_ret->Add(ret_sb,0, wxLEFT,10);
	bs_ret->AddSpacer(10);
	wxString initial_value;
	//Altura
	wxBoxSizer* bs_altura = new wxBoxSizer(wxHORIZONTAL);
	altura = new NumCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(60, 20), wxTE_CENTER|POSITIVO_APENAS);
	altura->setCasasDecimais(1);
	altura->Bind(wxEVT_TEXT, &RetanguloForm::alterado, this);
	bs_altura->Add(new wxStaticText(this,wxID_ANY,"H:", wxDefaultPosition, wxSize(30, 20)));
	bs_altura->AddSpacer(10);
	bs_altura->Add(altura,0, wxALIGN_CENTER|wxLEFT,10);
	bs_altura->AddSpacer(10);
	bs_altura->Add(new wxStaticText(this, wxID_ANY, "cm"));
	bs_altura->AddSpacer(10);
	bs_ret->Add(bs_altura);
	bs_ret->AddSpacer(10);
	//Base
	wxBoxSizer* bs_base = new wxBoxSizer(wxHORIZONTAL);
	base = new NumCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(60, 20), wxTE_CENTER |POSITIVO_APENAS);
	base->setCasasDecimais(1);
	base->Bind(wxEVT_TEXT, &RetanguloForm::alterado, this);
	bs_base->Add(new wxStaticText(this, wxID_ANY, "B:",wxDefaultPosition,wxSize(30,20)));
	bs_base->AddSpacer(10);
	bs_base->Add(base, 0, wxALIGN_CENTER | wxLEFT, 10);
	bs_base->AddSpacer(10);
	bs_base->Add(new wxStaticText(this, wxID_ANY, "cm"));
	bs_base->AddSpacer(10);
	bs_ret->Add(bs_base);
	bs_ret->AddSpacer(10);
	//Area bruta
	wxBoxSizer* bs_area = new wxBoxSizer(wxHORIZONTAL);
	area = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(60, 20), wxTE_CENTER | wxTE_READONLY | POSITIVO_APENAS);
	bs_area->Add(new wxStaticText(this, wxID_ANY, "A:", wxDefaultPosition, wxSize(30, 20)));
	bs_area->AddSpacer(10);
	bs_area->Add(area, 0, wxALIGN_CENTER | wxLEFT, 10);
	bs_area->AddSpacer(10);
	bs_area->Add(new wxStaticText(this, wxID_ANY, "cm²"));
	bs_area->AddSpacer(10);
	bs_ret->Add(bs_area);
	bs_ret->AddSpacer(10);
	//Inercia em X
	wxBoxSizer* bs_inercia_x = new wxBoxSizer(wxHORIZONTAL);
	inercia_x = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(60, 20), wxTE_CENTER |wxTE_READONLY |  POSITIVO_APENAS);
	bs_inercia_x->Add(new wxStaticText(this, wxID_ANY, "Ix:", wxDefaultPosition, wxSize(30, 20)));
	bs_inercia_x->AddSpacer(10);
	bs_inercia_x->Add(inercia_x, 0, wxALIGN_CENTER | wxLEFT, 10);
	bs_inercia_x->AddSpacer(10);
	bs_inercia_x->Add(new wxStaticText(this, wxID_ANY, "cm4"));
	bs_inercia_x->AddSpacer(10);
	bs_ret->Add(bs_inercia_x);
	bs_ret->AddSpacer(10);
	//Inercia em Y
	wxBoxSizer* bs_inercia_y = new wxBoxSizer(wxHORIZONTAL);
	inercia_y = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(60, 20), wxTE_CENTER | wxTE_READONLY | POSITIVO_APENAS);
	bs_inercia_y->Add(new wxStaticText(this, wxID_ANY, "Iy:", wxDefaultPosition, wxSize(30, 20)));
	bs_inercia_y->AddSpacer(10);
	bs_inercia_y->Add(inercia_y, 0, wxALIGN_CENTER | wxLEFT, 10);
	bs_inercia_y->AddSpacer(10);
	bs_inercia_y->Add(new wxStaticText(this, wxID_ANY, "cm4"));
	bs_inercia_y->AddSpacer(10);
	bs_ret->Add(bs_inercia_y);
	bs_ret->AddSpacer(10);
	//Modulo Resistente Elástico em X
	wxBoxSizer* bs_w_x = new wxBoxSizer(wxHORIZONTAL);
	w_x = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(60, 20), wxTE_CENTER | wxTE_READONLY | POSITIVO_APENAS);
	bs_w_x->Add(new wxStaticText(this, wxID_ANY, "Wx:", wxDefaultPosition, wxSize(30, 20)));
	bs_w_x->AddSpacer(10);
	bs_w_x->Add(w_x, 0, wxALIGN_CENTER | wxLEFT, 10);
	bs_w_x->AddSpacer(10);
	bs_w_x->Add(new wxStaticText(this, wxID_ANY, "cm³"));
	bs_w_x->AddSpacer(10);
	bs_ret->Add(bs_w_x);
	bs_ret->AddSpacer(10);
	//Modulo Resistente Elástico em Y
	wxBoxSizer* bs_w_y = new wxBoxSizer(wxHORIZONTAL);
	w_y = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(60, 20), wxTE_CENTER | wxTE_READONLY | POSITIVO_APENAS);
	bs_w_y->Add(new wxStaticText(this, wxID_ANY, "Wy:", wxDefaultPosition, wxSize(30, 20)));
	bs_w_y->AddSpacer(10);
	bs_w_y->Add(w_y, 0, wxALIGN_CENTER | wxLEFT, 10);
	bs_w_y->AddSpacer(10);
	bs_w_y->Add(new wxStaticText(this, wxID_ANY, "cm³"));
	bs_w_y->AddSpacer(10);
	bs_ret->Add(bs_w_y);
	bs_ret->AddSpacer(10);
	SetSizer(bs_ret);

	initial_value.sprintf("%.1f", params->var.h);
	altura->SetValue(initial_value);
	initial_value.sprintf("%.1f", params->var.b);
	base->SetValue(initial_value);

}
void RetanguloForm::alterado(wxCommandEvent& evt) {

	CalcParams* params = CalcParams::getInstance();
	wxString valor = evt.GetString();
	if (evt.GetEventObject() == base) {
		valor.ToCDouble(&params->var.b);

	}
	if (evt.GetEventObject() == altura) {
		valor.ToCDouble(&params->var.h);
	}
	wxString resultado;
	resultado.sprintf("%.0f", params->var.b * params->var.h );
	area->SetValue(resultado);
	resultado.sprintf("%.0f", (params->var.b * pow(params->var.h , 3) / 12));
	inercia_x->SetValue(resultado);
	resultado.sprintf("%.0f", (params->var.h * pow(params->var.b  ,3) / 12));
	inercia_y->SetValue(resultado);
	resultado.sprintf("%.0f", (params->var.b * pow(params->var.h, 2) / 6));
	w_x->SetValue(resultado);
	resultado.sprintf("%.0f", (params->var.h * pow(params->var.b, 2) / 6));
	w_y->SetValue(resultado);
	evt.Skip();
}
RetanguloForm::~RetanguloForm() {

}
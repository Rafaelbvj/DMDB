#include "Modelo.h"
Modelo::Modelo(wxWindow* pai) : wxDialog(pai,wxID_ANY,"Modelo de resistência",wxDefaultPosition,wxSize(1000,650)) {
	bs = new wxBoxSizer(wxHORIZONTAL);
	CalcParams* params = CalcParams::getInstance();
	
	wxBitmap* modelo_bmp = new wxBitmap("res\\modelo.bmp", wxBITMAP_TYPE_BMP);
	wxMask* modelo_mask = new wxMask(*modelo_bmp, wxColour(0xFFFFFFFF));
	modelo_bmp->SetMask(modelo_mask);
	wxStaticBitmap* modelo_sb = new wxStaticBitmap(this, wxID_ANY, wxBitmapBundle(*modelo_bmp));
	
	wxStaticBoxSizer* st = new wxStaticBoxSizer(wxVERTICAL, this, "Parâmetros de resistência (MPa)");
	st->AddSpacer(20);
	wxStaticText* vst = new wxStaticText(this, wxID_ANY, "Condição Verde:");
	vst->SetForegroundColour(0x0000EE00);
	st->Add(vst);
	st->AddSpacer(10);

	//Modulo de elasticidade
	wxBoxSizer* h_moe_v = new wxBoxSizer(wxHORIZONTAL);
	h_moe_v->Add(new wxStaticText(this,wxID_ANY,"MOE = ", wxDefaultPosition, wxSize(40, 20)));
	moe_b1_v = new NumCtrl(this, wxID_ANY,"", wxDefaultPosition, wxSize(70, 20), wxTE_CENTRE);
	h_moe_v->Add(moe_b1_v, 0, wxALIGN_CENTER | wxLEFT, 5);
	h_moe_v->Add(new wxStaticText(this, wxID_ANY, " x Db + "));
	moe_b0_v = new NumCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(70, 20), wxTE_CENTRE);
	h_moe_v->Add(moe_b0_v);
	//Tensao de ruptura na flexão
	wxBoxSizer* h_mor_v = new wxBoxSizer(wxHORIZONTAL);
	h_mor_v->Add(new wxStaticText(this, wxID_ANY, "MOR = ", wxDefaultPosition,wxSize(40,20)));
	mor_b1_v = new NumCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(70, 20), wxTE_CENTRE);
	h_mor_v->Add(mor_b1_v,0, wxALIGN_CENTER|wxLEFT,5);
	h_mor_v->Add(new wxStaticText(this, wxID_ANY, " x Db + "));
	mor_b0_v = new NumCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(70, 20), wxTE_CENTRE);
	h_mor_v->Add(mor_b0_v);
	//Tensao de ruptura na compressão paralela
	wxBoxSizer* h_cpa_v = new wxBoxSizer(wxHORIZONTAL);
	h_cpa_v->Add(new wxStaticText(this, wxID_ANY, "CPA = ", wxDefaultPosition, wxSize(40, 20)));
	cpa_b1_v = new NumCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(70, 20), wxTE_CENTRE);
	h_cpa_v->Add(cpa_b1_v,0, wxALIGN_CENTER | wxLEFT,5);
	h_cpa_v->Add(new wxStaticText(this, wxID_ANY, " x Db + "));
	cpa_b0_v = new NumCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(70, 20), wxTE_CENTRE);
	h_cpa_v->Add(cpa_b0_v);
	//Tensão de ruptura na compressão perpendicular
	wxBoxSizer* h_cpe_v = new wxBoxSizer(wxHORIZONTAL);
	h_cpe_v->Add(new wxStaticText(this, wxID_ANY, "CPE = ", wxDefaultPosition, wxSize(40, 20)));
	cpe_b1_v = new NumCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(70, 20), wxTE_CENTRE);
	h_cpe_v->Add(cpe_b1_v,0, wxALIGN_CENTER | wxLEFT,5);
	h_cpe_v->Add(new wxStaticText(this, wxID_ANY, " x Db + "));
	cpe_b0_v = new NumCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(70, 20), wxTE_CENTRE);
	h_cpe_v->Add(cpe_b0_v);
	//Tensão de ruptura no cisalhamento
	wxBoxSizer* h_cis_v = new wxBoxSizer(wxHORIZONTAL);
	h_cis_v->Add(new wxStaticText(this, wxID_ANY, "CIS = ", wxDefaultPosition, wxSize(40, 20)));
	cis_b1_v = new NumCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(70, 20), wxTE_CENTRE);
	h_cis_v->Add(cis_b1_v, 0, wxALIGN_CENTER | wxLEFT, 5);
	h_cis_v->Add(new wxStaticText(this, wxID_ANY, " x Db + "));
	cis_b0_v = new NumCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(70, 20), wxTE_CENTRE);
	h_cis_v->Add(cis_b0_v);

	st->Add(h_moe_v);
	st->AddSpacer(10);
	st->Add(h_mor_v);
	st->AddSpacer(10);
	st->Add(h_cpa_v);
	st->AddSpacer(10);
	st->Add(h_cpe_v); 
	st->AddSpacer(10);
	st->Add(h_cis_v);

	st->AddSpacer(20);
	wxStaticText* vst2 = new wxStaticText(this, wxID_ANY, "Condição Seca:");
	vst2->SetForegroundColour(0x0000AAAA);
	st->Add(vst2);
	st->AddSpacer(10);

	//Modulo de elasticidade
	wxBoxSizer* h_moe_s = new wxBoxSizer(wxHORIZONTAL);
	h_moe_s->Add(new wxStaticText(this, wxID_ANY, "MOE = ", wxDefaultPosition, wxSize(40, 20)));
	moe_b1_s = new NumCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(70, 20), wxTE_CENTRE);
	h_moe_s->Add(moe_b1_s, 0, wxALIGN_CENTER | wxLEFT, 5);
	h_moe_s->Add(new wxStaticText(this, wxID_ANY, " x Db + "));
	moe_b0_s = new NumCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(70, 20), wxTE_CENTRE);
	h_moe_s->Add(moe_b0_s);
	//Tensao de ruptura na flexão
	wxBoxSizer* h_mor_s = new wxBoxSizer(wxHORIZONTAL);
	h_mor_s->Add(new wxStaticText(this, wxID_ANY, "MOR = ", wxDefaultPosition, wxSize(40, 20)));
	mor_b1_s = new NumCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(70, 20), wxTE_CENTRE);
	h_mor_s->Add(mor_b1_s, 0, wxALIGN_CENTER | wxLEFT, 5);
	h_mor_s->Add(new wxStaticText(this, wxID_ANY, " x Db + "));
	mor_b0_s = new NumCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(70, 20), wxTE_CENTRE);
	h_mor_s->Add(mor_b0_s);
	//Tensao de ruptura na compressão paralela
	wxBoxSizer* h_cpa_s = new wxBoxSizer(wxHORIZONTAL);
	h_cpa_s->Add(new wxStaticText(this, wxID_ANY, "CPA = ", wxDefaultPosition, wxSize(40, 20)));
	cpa_b1_s = new NumCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(70, 20), wxTE_CENTRE);
	h_cpa_s->Add(cpa_b1_s, 0, wxALIGN_CENTER | wxLEFT, 5);
	h_cpa_s->Add(new wxStaticText(this, wxID_ANY, " x Db + "));
	cpa_b0_s = new NumCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(70, 20), wxTE_CENTRE);
	h_cpa_s->Add(cpa_b0_s);
	//Tensão de ruptura na compressão perpendicular
	wxBoxSizer* h_cpe_s = new wxBoxSizer(wxHORIZONTAL);
	h_cpe_s->Add(new wxStaticText(this, wxID_ANY, "CPE = ", wxDefaultPosition, wxSize(40, 20)));
	cpe_b1_s = new NumCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(70, 20), wxTE_CENTRE);
	h_cpe_s->Add(cpe_b1_s, 0, wxALIGN_CENTER | wxLEFT, 5);
	h_cpe_s->Add(new wxStaticText(this, wxID_ANY, " x Db + "));
	cpe_b0_s = new NumCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(70, 20), wxTE_CENTRE);
	h_cpe_s->Add(cpe_b0_s);
	//Tensão de ruptura no cisalhamento
	wxBoxSizer* h_cis_s = new wxBoxSizer(wxHORIZONTAL);
	h_cis_s->Add(new wxStaticText(this, wxID_ANY, "CIS = ", wxDefaultPosition, wxSize(40, 20)));
	cis_b1_s = new NumCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(70, 20), wxTE_CENTRE);
	h_cis_s->Add(cis_b1_s, 0, wxALIGN_CENTER | wxLEFT, 5);
	h_cis_s->Add(new wxStaticText(this, wxID_ANY, " x Db + "));
	cis_b0_s = new NumCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(70, 20), wxTE_CENTRE);
	h_cis_s->Add(cis_b0_s);


	st->Add(h_moe_s);
	st->AddSpacer(10);
	st->Add(h_mor_s);
	st->AddSpacer(10);
	st->Add(h_cpa_s);
	st->AddSpacer(10);
	st->Add(h_cpe_s);
	st->AddSpacer(10);
	st->Add(h_cis_s);

	bs->Add(modelo_sb);
	wxBoxSizer* botao = new wxBoxSizer(wxVERTICAL);
	botao->Add(st);
	salvar = new wxButton(this, 10015, "Salvar alterações", wxDefaultPosition, wxSize(100, 30));
	salvar->Bind(wxEVT_BUTTON, &Modelo::salvar_botao, this);
	botao->AddSpacer(20);
	botao->Add(salvar,0,wxALIGN_CENTER,0);
	bs->Add(botao);
	SetSizer(bs);
	update_fields();
}
int Modelo::ShowModal(){
	wxDialog::ShowModal();
	update_fields();
	return 0;
}
void Modelo::salvar_botao(wxCommandEvent& evt) {
	CalcParams* params = CalcParams::getInstance();

	//Verde
	cpa_b1_v->GetValue().ToDouble(&params->var.coeficientes_verde[0][0]);
	cpa_b0_v->GetValue().ToDouble(&params->var.coeficientes_verde[0][1]);

	mor_b1_v->GetValue().ToDouble(&params->var.coeficientes_verde[1][0]);
	mor_b0_v->GetValue().ToDouble(&params->var.coeficientes_verde[1][1]);

	moe_b1_v->GetValue().ToDouble(&params->var.coeficientes_verde[2][0]);
	moe_b0_v->GetValue().ToDouble(&params->var.coeficientes_verde[2][1]);

	cpe_b1_v->GetValue().ToDouble(&params->var.coeficientes_verde[3][0]);
	cpe_b0_v->GetValue().ToDouble(&params->var.coeficientes_verde[3][1]);

	cis_b1_v->GetValue().ToDouble(&params->var.coeficientes_verde[4][0]);
	cis_b0_v->GetValue().ToDouble(&params->var.coeficientes_verde[4][1]);

	//Seca
	cpa_b1_s->GetValue().ToDouble(&params->var.coeficientes_seca[0][0]);
	cpa_b0_s->GetValue().ToDouble(&params->var.coeficientes_seca[0][1]);

	mor_b1_s->GetValue().ToDouble(&params->var.coeficientes_seca[1][0]);
	mor_b0_s->GetValue().ToDouble(&params->var.coeficientes_seca[1][1]);

	moe_b1_s->GetValue().ToDouble(&params->var.coeficientes_seca[2][0]);
	moe_b0_s->GetValue().ToDouble(&params->var.coeficientes_seca[2][1]);

	cpe_b1_s->GetValue().ToDouble(&params->var.coeficientes_seca[3][0]);
	cpe_b0_s->GetValue().ToDouble(&params->var.coeficientes_seca[3][1]);

	cis_b1_s->GetValue().ToDouble(&params->var.coeficientes_seca[4][0]);
	cis_b0_s->GetValue().ToDouble(&params->var.coeficientes_seca[4][1]);

	wxMessageBox("Salvo!");
}
void Modelo::update_fields() {
	CalcParams* params = CalcParams::getInstance();
	wxString str;
	//Verde
	//CPA
	str.sprintf("%.4f", params->var.coeficientes_verde[0][0]);
	cpa_b1_v->SetValue(str);
	str.sprintf("%.4f", params->var.coeficientes_verde[0][1]);
	cpa_b0_v->SetValue(str);
	//MOR
	str.sprintf("%.4f", params->var.coeficientes_verde[1][0]);
	mor_b1_v->SetValue(str);
	str.sprintf("%.4f", params->var.coeficientes_verde[1][1]);
	mor_b0_v->SetValue(str);
	//MOE
	str.sprintf("%.4f", params->var.coeficientes_verde[2][0]);
	moe_b1_v->SetValue(str);
	str.sprintf("%.4f", params->var.coeficientes_verde[2][1]);
	moe_b0_v->SetValue(str);
	//CPE
	str.sprintf("%.4f", params->var.coeficientes_verde[3][0]);
	cpe_b1_v->SetValue(str);
	str.sprintf("%.4f", params->var.coeficientes_verde[3][1]);
	cpe_b0_v->SetValue(str);
	//CIS
	str.sprintf("%.4f", params->var.coeficientes_verde[4][0]);
	cis_b1_v->SetValue(str);
	str.sprintf("%.4f", params->var.coeficientes_verde[4][1]);
	cis_b0_v->SetValue(str);

	//Seca
	//CPA
	str.sprintf("%.4f", params->var.coeficientes_seca[0][0]);
	cpa_b1_s->SetValue(str);
	str.sprintf("%.4f", params->var.coeficientes_seca[0][1]);
	cpa_b0_s->SetValue(str);
	//MOR
	str.sprintf("%.4f", params->var.coeficientes_seca[1][0]);
	mor_b1_s->SetValue(str);
	str.sprintf("%.4f", params->var.coeficientes_seca[1][1]);
	mor_b0_s->SetValue(str);
	//MOE
	str.sprintf("%.4f", params->var.coeficientes_seca[2][0]);
	moe_b1_s->SetValue(str);
	str.sprintf("%.4f", params->var.coeficientes_seca[2][1]);
	moe_b0_s->SetValue(str);
	//CPE
	str.sprintf("%.4f", params->var.coeficientes_seca[3][0]);
	cpe_b1_s->SetValue(str);
	str.sprintf("%.4f", params->var.coeficientes_seca[3][1]);
	cpe_b0_s->SetValue(str);
	//CIS
	str.sprintf("%.4f", params->var.coeficientes_seca[4][0]);
	cis_b1_s->SetValue(str);
	str.sprintf("%.4f", params->var.coeficientes_seca[4][1]);
	cis_b0_s->SetValue(str);
}

Modelo::~Modelo() {

}

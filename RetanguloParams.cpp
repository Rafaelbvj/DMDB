#include "RetanguloParams.h"
RetanguloParams::RetanguloParams(wxWindow* pai) : wxNotebook(pai, wxID_ANY, wxPoint(0, 0)) {
	//Layout
	panel_tracao = new wxPanel(this, wxID_ANY);
	st_1 = new wxBoxSizer(wxVERTICAL);
	st_1->AddSpacer(20);
	h_al_1 = new wxBoxSizer(wxHORIZONTAL);
	v_al_1 = new wxBoxSizer(wxVERTICAL);
	wxBitmap* tracao_ret = new wxBitmap("res\\tracao_ret.bmp", wxBITMAP_TYPE_BMP);
	wxMask* tracao_ret_mask = new wxMask(*tracao_ret, wxColour(0xFFFFFFFF));
	tracao_ret->SetMask(tracao_ret_mask);
	wxStaticBitmap* tracao_bmp = new wxStaticBitmap(panel_tracao, wxID_ANY, wxBitmapBundle(*tracao_ret));
	h_al_1->Add(tracao_bmp);
	h_al_1->AddSpacer(20);
	wxBoxSizer* v_al_1_2 = new wxBoxSizer(wxVERTICAL);
	v_al_1_2->Add(new wxStaticText(panel_tracao, wxID_ANY, "Diâmetro dos furos (mm):"));
	v_al_1_2->AddSpacer(10);
	diametro_furos = new NumCtrl(panel_tracao, wxID_ANY,"", wxDefaultPosition, wxSize(100, 20),wxTE_CENTRE |POSITIVO_APENAS);
	diametro_furos->setCasasDecimais(0);
	v_al_1_2->Add(diametro_furos);
	v_al_1_2->AddSpacer(10);
	v_al_1_2->Add(new wxStaticText(panel_tracao, wxID_ANY, "N:"));
	v_al_1_2->AddSpacer(10);
	num_furos = new NumCtrl(panel_tracao, wxID_ANY, "", wxDefaultPosition, wxSize(100, 20), wxTE_CENTRE | POSITIVO_APENAS);
	t_calc = new wxButton(panel_tracao, 10009, "Verificar Solicitação", wxDefaultPosition, wxSize(150,30));
	t_calc->Bind(wxEVT_BUTTON, &RetanguloParams::calcular_tracao,this);
	num_furos->setCasasDecimais(0);
	v_al_1_2->Add(num_furos);
	h_al_1->Add(v_al_1_2);
	v_al_1->Add(h_al_1);
	v_al_1->AddSpacer(20);
	st_1->Add(v_al_1);
	st_1->Add(t_calc,0,wxLEFT,20);
	panel_tracao->SetSizer(st_1);
	AddPage(panel_tracao, "Tração");
	
	panel_comp = new wxPanel(this, wxID_ANY);
	v_al_2 = new wxBoxSizer(wxVERTICAL);
	h_al_2 = new wxBoxSizer(wxHORIZONTAL);
	v_al_2_1 = new wxBoxSizer(wxVERTICAL);
	c_calc = new wxButton(panel_comp, 10020, "Verificar Solicitação", wxDefaultPosition, wxSize(150, 30));
	c_calc->Bind(wxEVT_BUTTON, &RetanguloParams::calcular_comp, this);
	wxBitmap* comp_ret = new wxBitmap("res\\comp.bmp", wxBITMAP_TYPE_BMP);
	wxMask* comp_ret_mask = new wxMask(*comp_ret, wxColour(0xFFFFFFFF));
	comp_ret->SetMask(comp_ret_mask);
	wxStaticBitmap* comp_bmp = new wxStaticBitmap(panel_comp, wxID_ANY, wxBitmapBundle(*comp_ret));
	comprimento_barra = new NumCtrl(panel_comp, wxID_ANY,"",wxDefaultPosition,wxSize(100,20),wxTE_CENTRE|POSITIVO_APENAS);
	wxString d[] = { "Madeira serrada maciça", "Madeira lamelada" };
	beta_r = new wxRadioBox(panel_comp, wxID_ANY, "Tipo de madeira", wxDefaultPosition, wxDefaultSize, wxArrayString(2, d),1, wxRA_SPECIFY_COLS);
	comprimento_barra->setCasasDecimais(2);
	v_al_2_1->Add(new wxStaticText(panel_comp, wxID_ANY, "Comprimento de flambagem L (m):"));
	v_al_2_1->AddSpacer(10);
	v_al_2_1->Add(comprimento_barra);
	v_al_2_1->AddSpacer(10);
	v_al_2_1->Add(beta_r);
	h_al_2->Add(comp_bmp);
	h_al_2->AddSpacer(20);
	h_al_2->Add(v_al_2_1);
	v_al_2->Add(h_al_2,0,wxTOP,20);
	v_al_2->AddSpacer(20);
	v_al_2->Add(c_calc,0,wxLEFT,20);
	panel_comp->SetSizer(v_al_2);
	AddPage(panel_comp, "Compressao Simples");

	
	panel_flexao = new wxPanel(this,wxID_ANY);
	v_al_3 = new wxBoxSizer(wxVERTICAL);
	v_al_3->AddSpacer(20);
	h_al_3 = new wxBoxSizer(wxHORIZONTAL);
	h_al_3_b = new wxBoxSizer(wxHORIZONTAL);
	f_calc = new wxButton(panel_flexao, 10023, "Verificar Solicitação", wxDefaultPosition, wxSize(150, 30));
	f_calc->Bind(wxEVT_BUTTON, &RetanguloParams::calcular_flexao, this);
	wxBitmap* flex_ret = new wxBitmap("res\\flexao.bmp", wxBITMAP_TYPE_BMP);
	wxMask* flex_ret_mask = new wxMask(*flex_ret, wxColour(0xFFFFFFFF));
	flex_ret->SetMask(flex_ret_mask);
	wxStaticBitmap* flex_bmp = new wxStaticBitmap(panel_flexao, wxID_ANY, wxBitmapBundle(*flex_ret));

	wxBitmap* flex_ret_b = new wxBitmap("res\\flexao_b.bmp", wxBITMAP_TYPE_BMP);
	wxMask* flex_ret_mask_b = new wxMask(*flex_ret_b, wxColour(0xFFFFFFFF));
	flex_ret_b->SetMask(flex_ret_mask_b);
	wxStaticBitmap* flex_bmp_b = new wxStaticBitmap(panel_flexao, wxID_ANY, wxBitmapBundle(*flex_ret_b));

	h_al_3->Add(flex_bmp);
	h_al_3_b->Add(flex_bmp_b);
	v_al_3->Add(h_al_3);
	v_al_3->Add(h_al_3_b);
	v_al_3->AddSpacer(10);
	v_al_3->Add(f_calc,0,wxLEFT,20);
	panel_flexao->SetSizer(v_al_3);
	AddPage(panel_flexao, "Flexão Simples");

	panel_flexao_composta = new wxPanel(this,wxID_ANY);
	st_4 = new wxBoxSizer(wxVERTICAL);
	
	wxBitmap* flex_obliqua = new wxBitmap("res\\flexao_obliqua.bmp", wxBITMAP_TYPE_BMP);
	wxMask* flex_obliqua_mask = new wxMask(*flex_obliqua, wxColour(0xFFFFFFFF));
	flex_obliqua->SetMask(flex_obliqua_mask);
	wxStaticBitmap* flex_obliqua_bmp = new wxStaticBitmap(panel_flexao_composta, wxID_ANY, wxBitmapBundle(*flex_obliqua));
	v_al_5 = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer *h_al_2 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* v_al_5_1 = new wxBoxSizer(wxVERTICAL);

	comprimento_barra2 = new NumCtrl(panel_flexao_composta, wxID_ANY, "", wxDefaultPosition, wxSize(100, 20), wxTE_CENTRE | POSITIVO_APENAS);
	v_al_5_1->AddSpacer(20);
	v_al_5_1->Add(new wxStaticText(panel_flexao_composta, wxID_ANY, "Comprimento de flambagem L (m):"));
	v_al_5_1->AddSpacer(10);
	v_al_5_1->Add(comprimento_barra2);
	v_al_5_1->AddSpacer(10);
	wxString g[] = { "Madeira serrada maciça", "Madeira lamelada" };
	beta_r2 = new wxRadioBox(panel_flexao_composta, wxID_ANY, "Tipo de madeira", wxDefaultPosition, wxDefaultSize, wxArrayString(2, g), 1, wxRA_SPECIFY_COLS);
	v_al_5_1->Add(beta_r2);
	h_al_2->Add(flex_obliqua_bmp);
	h_al_2->AddSpacer(20);
	h_al_2->Add(v_al_5_1);
	v_al_5->Add(h_al_2);
	fc_calc = new wxButton(panel_flexao_composta, wxID_ANY, "Verificar solicitação", wxDefaultPosition, wxSize(150, 30));
	fc_calc->Bind(wxEVT_BUTTON, &RetanguloParams::calcular_flexao_obliqua, this);
	v_al_5->AddSpacer(20);
	v_al_5->Add(fc_calc);
	st_4->Add(v_al_5, 0, wxEXPAND|wxLEFT, 20);
	panel_flexao_composta->SetSizer(st_4);
	AddPage(panel_flexao_composta, "Flexão Composta");
	
	panel_cis = new wxPanel(this,wxID_ANY);
	h_cis_v = new wxBoxSizer(wxHORIZONTAL);
	wxBitmap* cis_v = new wxBitmap("res\\cis_v.bmp", wxBITMAP_TYPE_BMP);
	wxMask* cis_mask_v = new wxMask(*cis_v, wxColour(0xFFFFFFFF));
	cis_v->SetMask(cis_mask_v);
	wxStaticBitmap* cis_v_bmp = new wxStaticBitmap(panel_cis, wxID_ANY, wxBitmapBundle(*cis_v));
	h_cis_v->Add(cis_v_bmp);

	v_al_6 = new wxBoxSizer(wxVERTICAL);
	v_al_6->AddSpacer(20);
	v_al_6->Add(h_cis_v);
	cis_calc = new wxButton(panel_cis, wxID_ANY, "Verificar Solicitação",wxDefaultPosition,wxSize(150,30));
	cis_calc->Bind(wxEVT_BUTTON, &RetanguloParams::calcular_cis, this);
	v_al_6->AddSpacer(10);
	v_al_6->Add(cis_calc,0,wxLEFT,20);
	panel_cis->SetSizer(v_al_6);
	AddPage(panel_cis, "Cisalhamento");
}

void RetanguloParams::calcular_flexao_obliqua(wxCommandEvent& evt) {
	CalcParams* params = CalcParams::getInstance();

	if (params->var.b * params->var.h == 0) {
		wxMessageBox("É necessário definir as dimensões da seção transversal", "Erro", wxOK | wxICON_ERROR);
		return;
	}
	if (params->var.momentox ==0 && params->var.momentoy == 0) {
		wxMessageBox("É necessário definir o momento solicitante", "Erro", wxOK | wxICON_ERROR);
		return;
	}
	double L = 0;
	double beta = beta_r2->GetSelection() ? 0.1 : 0.2;
	comprimento_barra2->GetValue().ToCDouble(&L);
	if (L == 0) {
		wxMessageBox("É necessário definir o comprimento da barra", "Erro", wxOK | wxICON_ERROR);
		return;
	}

	if (resultado_flexao_tracao == nullptr) {
		resultado_flexao_tracao = new wxStaticText(panel_flexao_composta, wxID_ANY, "");
		resultado_flexao_tracao->SetFont(*params->var.fonte_resultado);
		v_al_5->Insert(1,resultado_flexao_tracao);
		v_al_5->InsertSpacer(2, 10);
		resultado_flexao_comp = new wxStaticText(panel_flexao_composta, wxID_ANY, "");
		resultado_flexao_comp->SetFont(*params->var.fonte_resultado);
		v_al_5->Insert(3, resultado_flexao_comp);
		v_al_5->InsertSpacer(4, 10);

		resultado_flexao_comp_inst = new wxStaticText(panel_flexao_composta, wxID_ANY, "");
		resultado_flexao_comp_inst->SetFont(*params->var.fonte_resultado);
		v_al_5->Insert(5, resultado_flexao_comp_inst);
		v_al_5->InsertSpacer(6, 10);

		st_4->Layout();
	}
	double msx = params->var.momentox;
	double msy = params->var.momentoy;

	double phic = (params->get_KMOD() / params->var.gama_w[0]); //Compressão
	double phib = (params->get_KMOD() / params->var.gama_w[1]); //Flexão
	double phit = (params->get_KMOD() / params->var.gama_w[2]); //Tração
	

	double wx = params->var.b * pow(params->var.h, 2) / 6;
	double wy = params->var.h * pow(params->var.b, 2) / 6;

	double mrx = phib * wx * params->get_mat(MOR) * 10.1972 / 100;
	double mry = phib * wy * params->get_mat(MOR) * 10.1972 / 100;
	
	double area = params->var.b * params->var.h;
	double nr= phic * area * params->get_mat(CPA) * 10.1972 ;
	double tr = phit * area *  params->get_mat(CPA) * 10.1972 ;
	
	if (params->var.met_calc & 0xFF00) {
		tr *= 1.3;
	}
	if (params->var.met_calc & 0xFF0000) {
		tr = area * (params->get_KMOD() / params->var.gama_w[2]) * params->get_mat(MOR) * 10.1972;
	}
	double km = 0.7;
	double res_1 = km * msx / mry + msy / mry;
	double res_2 = msx / mry + km * msy / mry;
	double flexo_tc1 = res_1 +  params->var.normal / tr;
	double flexo_tc2 = res_2 + params->var.normal / tr;
	if (params->var.normal == 0) {
		resultado_flexao_comp->SetLabelText("");
		resultado_flexao_comp_inst->SetLabelText("");
	}
	if (flexo_tc1 > 1 || flexo_tc2 > 1) {
		resultado_flexao_tracao->SetForegroundColour(0x000000FF);
		if (params->var.normal == 0) {
			resultado_flexao_tracao->SetLabelText("Flexão oblíqua: Risco de ruptura!");
			return;
		}
		resultado_flexao_tracao->SetLabelText("Flexotração: Risco de ruptura!");
		
	}
	else {
		resultado_flexao_tracao->SetForegroundColour(0x0000FF00);
		if (params->var.normal == 0) {
			resultado_flexao_tracao->SetLabelText("Flexão oblíqua: OK!");
			return;
		}
		resultado_flexao_tracao->SetLabelText("Flexotração: OK!");
	}
	
	flexo_tc1 = res_1+ pow(params->var.normal / nr, 2);
	flexo_tc2 = res_2 + pow(params->var.normal / nr, 2);
	if (flexo_tc1 > 1 || flexo_tc2 > 1) {
		resultado_flexao_comp->SetForegroundColour(0x000000FF);
		resultado_flexao_comp->SetLabelText("Flexocompressão: Risco de ruptura!");
	}
	else {
		resultado_flexao_comp->SetForegroundColour(0x0000FF00);
		resultado_flexao_comp->SetLabelText("Flexocompressão: OK!");
	}

	
	double e_real_x = L * 100 / sqrt((params->var.b * pow(params->var.h, 3) / 12) / (params->var.b * params->var.h));
	double e_rel_x = (e_real_x / M_PI) * sqrt(params->get_mat(CPA) / (0.7 * params->get_mat(Ecs)));

	double Kcx;
	if (e_rel_x <= 0.3f) {  //Barra Curta
		Kcx = 1;
	}
	else {

		double kx = 0.5 * (1 + beta * (e_rel_x - 0.3) + pow(e_rel_x, 2));
		Kcx = 1 / (kx + sqrt(pow(kx, 2) - pow(e_rel_x, 2)));

	}
	double e_real_y = L * 100 / sqrt((params->var.h * pow(params->var.b, 3) / 12) / (params->var.b * params->var.h));

	double e_rel_y = (e_real_y / M_PI) * sqrt(params->get_mat(CPA) / (0.7 * params->get_mat(Ecs)));
	
	double Kcy;
	if (e_rel_y <= 0.3f) {  //Barra Curta
		Kcy = 1;
	}
	else {
		double ky = 0.5 * (1 + beta * (e_rel_y - 0.3) + pow(e_rel_y, 2));
		Kcy = 1 / (ky + sqrt(pow(ky, 2) - pow(e_rel_y, 2)));
	}

	double KC = (Kcx < Kcy) ? Kcx : Kcy;
	
	nr = phic * KC * area * params->get_mat(CPA) * 10.1972 ;
	flexo_tc1 = res_1 + params->var.normal / nr;
	flexo_tc2 = res_2 + params->var.normal / nr;
	if (flexo_tc1 > 1 || flexo_tc2 > 1) {
		resultado_flexao_comp_inst->SetForegroundColour(0x000000FF);
		resultado_flexao_comp_inst->SetLabelText("Estabilidade na flexocompressão: instável!");
		return;
	}
	resultado_flexao_comp_inst->SetForegroundColour(0x0000FF00);
	resultado_flexao_comp_inst->SetLabelText("Estabilidade na flexocompressão: OK!");
	

}
void RetanguloParams::calcular_cis(wxCommandEvent& evt) {
	CalcParams* params = CalcParams::getInstance();
	if (params->var.b * params->var.h == 0) {
		wxMessageBox("É necessário definir as dimensões da seção transversal", "Erro", wxOK | wxICON_ERROR);
		return;
	}
	if (resultado_cis == nullptr) {
		resultado_cis = new wxStaticText(panel_cis, wxID_ANY, "");
		resultado_cis->SetFont(*params->var.fonte_resultado);
		h_cis_v->AddSpacer(20);
		h_cis_v->Add( resultado_cis,0,wxALIGN_CENTER,0);
		v_al_6->Layout();
		
	}
	double phic = (params->get_KMOD() / params->var.gama_w[3]);
	double Ix = params->var.b * pow(params->var.h , 3) / 12;
	double momento_estatico = params->var.b * pow(params->var.h/2, 2) / 2;
	double resultado = phic * (params->var.b * Ix / momento_estatico) * params->get_mat(CIS) * 10.1972;
	wxString result;
	result.sprintf("Vr = %.3f kgf", resultado);
	if (params->var.cisalhamento > 0) {
		if (resultado > params->var.cisalhamento) {
			resultado_cis->SetForegroundColour(0x000000FF00);
			result.sprintf("%s > V = %.3f kgf (OK!)",result, params->var.cisalhamento);
		}
		if (resultado < params->var.cisalhamento) {
			resultado_cis->SetForegroundColour(0x00000000FF);
			result.sprintf("%s > V = %.3f kgf (Ruptura!)",result, params->var.cisalhamento);
		}
	}
	resultado_cis->SetLabelText(result);

}
void RetanguloParams::calcular_flexao(wxCommandEvent& evt) {
	CalcParams* params = CalcParams::getInstance();
	//Verificar se existe uma seção transversal
	if (params->var.b * params->var.h == 0) {
		wxMessageBox("É necessário definir as dimensões da seção transversal", "Erro", wxOK | wxICON_ERROR);
		return;
	}
	wxBoxSizer *v_f_r = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* v_f_r_b = new wxBoxSizer(wxVERTICAL);
	if (resultado_flexao_x == nullptr) {
		resultado_flexao_x = new wxStaticText(panel_flexao,wxID_ANY,"");
		resultado_flexao_x->SetFont(*params->var.fonte_resultado);
		v_f_r->Add(resultado_flexao_x);
		v_f_r->AddSpacer(10);
		
	}
	if (resultado_flexao_y == nullptr) {
		resultado_flexao_y = new wxStaticText(panel_flexao, wxID_ANY, "");
		resultado_flexao_y->SetFont(*params->var.fonte_resultado);
		v_f_r_b->Add(resultado_flexao_y);
	}
	h_al_3->AddSpacer(20);
	h_al_3->Add(v_f_r,0,wxALIGN_CENTER,0);
	h_al_3_b->AddSpacer(20);
	h_al_3_b->Add(v_f_r_b, 0, wxALIGN_CENTER, 0);
	v_al_3->Layout();
	double resultado_x = (params->get_KMOD() / params->var.gama_w[1]) * (params->var.b * pow(params->var.h,2)/6) *  params->get_mat(MOR) * 10.1972/100;
	double resultado_y = (params->get_KMOD() / params->var.gama_w[1]) * (params->var.h * pow(params->var.b, 2) / 6) * params->get_mat(MOR) * 10.1972 / 100;
	wxString result; 
	 
	if (resultado_x > abs(params->var.momentox)) {
		resultado_flexao_x->SetForegroundColour(0x0000FF00);
		result.sprintf("Mrx = %.3f kgf.m > Msx = %.3f kgf.m (OK!)", resultado_x, abs(params->var.momentox));
	}
	if (resultado_x < abs(params->var.momentox)) {
		resultado_flexao_x->SetForegroundColour(0x000000FF);
		result.sprintf("Mrx = %.3f kgf.m < Msx = %.3f kgf.m (Ruptura!)", resultado_x, abs(params->var.momentox));
	}
	resultado_flexao_x->SetLabelText(result);

	if (resultado_y > abs(params->var.momentoy)) {
		resultado_flexao_y->SetForegroundColour(0x0000FF00);
		result.sprintf("Mry = %.3f kgf.m > Msy = %.3f kgf.m (OK!)", resultado_y, abs(params->var.momentoy));
	}
	if (resultado_y < abs(params->var.momentoy)) {
		resultado_flexao_y->SetForegroundColour(0x000000FF);
		result.sprintf("Mry = %.3f kgf.m < Msy = %.3f kgf.m (Ruptura!)", resultado_y, abs(params->var.momentoy));
	}
	resultado_flexao_y->SetLabelText(result);
}
void RetanguloParams::calcular_comp(wxCommandEvent& evt) {
	CalcParams* params = CalcParams::getInstance();
	double L = 0;
	comprimento_barra->GetValue().ToCDouble(&L);
	if(L == 0){
		wxMessageBox("É necessário definir o comprimento da barra", "Erro", wxOK | wxICON_ERROR);
		return;
	}
	//Verificar se existe uma seção transversal
	if (params->var.b * params->var.h == 0) {
		wxMessageBox("É necessário definir as dimensões da seção transversal", "Erro", wxOK | wxICON_ERROR);
		return;
	}

	double beta = beta_r->GetSelection()? 0.1 : 0.2;

	if (eixo_x == nullptr) {
		eixo_x = new wxStaticBoxSizer(wxVERTICAL, panel_comp, "Eixo X");
		//Lambda X
		wxBitmap* lambda_x_bmp = new wxBitmap("res\\lambda_x.bmp", wxBITMAP_TYPE_BMP);
		wxMask* lambda_x_mask = new wxMask(*lambda_x_bmp, wxColour(0xFFFFFFFF));
		lambda_x_bmp->SetMask(lambda_x_mask);
		wxStaticBitmap* lambda_x = new wxStaticBitmap(panel_comp, wxID_ANY, wxBitmapBundle(*lambda_x_bmp));
		wxBoxSizer* h_l_x = new wxBoxSizer(wxHORIZONTAL);
		h_l_x->Add(lambda_x);
		esbeltez_x_real = new wxTextCtrl(panel_comp, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(80, 20), wxTE_READONLY|wxTE_CENTRE);
		h_l_x->AddSpacer(15);
		h_l_x->Add(esbeltez_x_real);
		eixo_x->Add(h_l_x);
		eixo_x->AddSpacer(10);


		//Lambda X relativo
		wxBitmap* lambda_x_rel_bmp = new wxBitmap("res\\lambda_x_rel.bmp", wxBITMAP_TYPE_BMP);
		wxMask* lambda_x_rel_mask = new wxMask(*lambda_x_rel_bmp, wxColour(0xFFFFFFFF));
		lambda_x_rel_bmp->SetMask(lambda_x_rel_mask);
		wxStaticBitmap* lambda_x_rel = new wxStaticBitmap(panel_comp, wxID_ANY, wxBitmapBundle(*lambda_x_rel_bmp));
		wxBoxSizer* h_l_x_rel = new wxBoxSizer(wxHORIZONTAL);
		esbeltez_x_rel = new wxTextCtrl(panel_comp, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(80, 20), wxTE_READONLY | wxTE_CENTRE);
		h_l_x_rel->Add(lambda_x_rel);
		h_l_x_rel->Add(esbeltez_x_rel);
		eixo_x->Add(h_l_x_rel);
		eixo_x->AddSpacer(10);

		//Kcx
		wxBitmap* kc_x_bmp = new wxBitmap("res\\kc_x.bmp", wxBITMAP_TYPE_BMP);
		wxMask* kc_x_mask = new wxMask(*kc_x_bmp, wxColour(0xFFFFFFFF));
		kc_x_bmp->SetMask(kc_x_mask);
		wxStaticBitmap* kc_x = new wxStaticBitmap(panel_comp, wxID_ANY, wxBitmapBundle(*kc_x_bmp));
		wxBoxSizer* h_kc_x = new wxBoxSizer(wxHORIZONTAL);
		kcx = new wxTextCtrl(panel_comp, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(80, 20), wxTE_READONLY | wxTE_CENTRE);
		h_kc_x->Add(kc_x);
		h_kc_x->AddSpacer(8);
		h_kc_x->Add(kcx);
		eixo_x->Add(h_kc_x);

		eixo_y = new wxStaticBoxSizer(wxVERTICAL, panel_comp, "Eixo Y");
		//Lambda Y
		wxBitmap* lambda_y_bmp = new wxBitmap("res\\lambda_y.bmp", wxBITMAP_TYPE_BMP);
		wxMask* lambda_y_mask = new wxMask(*lambda_y_bmp, wxColour(0xFFFFFFFF));
		lambda_y_bmp->SetMask(lambda_y_mask);
		wxStaticBitmap* lambda_y = new wxStaticBitmap(panel_comp, wxID_ANY, wxBitmapBundle(*lambda_y_bmp));
		wxBoxSizer* h_l_y = new wxBoxSizer(wxHORIZONTAL);
		h_l_y->Add(lambda_y);
		esbeltez_y_real = new wxTextCtrl(panel_comp, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(80, 20), wxTE_READONLY | wxTE_CENTRE);
		h_l_y->AddSpacer(15);
		h_l_y->Add(esbeltez_y_real);
		eixo_y->Add(h_l_y);
		eixo_y->AddSpacer(10);


		//Lambda Y relativo
		wxBitmap* lambda_y_rel_bmp = new wxBitmap("res\\lambda_y_rel.bmp", wxBITMAP_TYPE_BMP);
		wxMask* lambda_y_rel_mask = new wxMask(*lambda_y_rel_bmp, wxColour(0xFFFFFFFF));
		lambda_x_rel_bmp->SetMask(lambda_y_rel_mask);
		wxStaticBitmap* lambda_y_rel = new wxStaticBitmap(panel_comp, wxID_ANY, wxBitmapBundle(*lambda_y_rel_bmp));
		wxBoxSizer* h_l_y_rel = new wxBoxSizer(wxHORIZONTAL);
		esbeltez_y_rel = new wxTextCtrl(panel_comp, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(80, 20), wxTE_READONLY | wxTE_CENTRE);
		h_l_y_rel->Add(lambda_y_rel);
		h_l_y_rel->Add(esbeltez_y_rel);
		eixo_y->Add(h_l_y_rel);
		eixo_y->AddSpacer(10);

		//Kcy
		wxBitmap* kc_y_bmp = new wxBitmap("res\\kc_y.bmp", wxBITMAP_TYPE_BMP);
		wxMask* kc_y_mask = new wxMask(*kc_y_bmp, wxColour(0xFFFFFFFF));
		kc_y_bmp->SetMask(kc_y_mask);
		wxStaticBitmap* kc_y = new wxStaticBitmap(panel_comp, wxID_ANY, wxBitmapBundle(*kc_y_bmp));
		wxBoxSizer* h_kc_y = new wxBoxSizer(wxHORIZONTAL);
		kcy = new wxTextCtrl(panel_comp, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(80, 20), wxTE_READONLY | wxTE_CENTRE);

		h_kc_y->Add(kc_y);
		h_kc_y->AddSpacer(8);
		h_kc_y->Add(kcy);
		eixo_y->Add(h_kc_y);

		
		h_al_2->AddSpacer(40);
		h_al_2->Add(eixo_x);
		h_al_2->AddSpacer(20);
		h_al_2->Add(eixo_y);

		resultado_comp = new wxStaticText(panel_comp, wxID_ANY, "");
		v_al_2->InsertSpacer(2, 20);
		v_al_2->Insert(2,resultado_comp);
		resultado_comp->SetFont(*params->var.fonte_resultado);

		v_al_2->Layout();

	}
	wxString result;
	double e_real_x = L * 100/ sqrt((params->var.b * pow(params->var.h,3) / 12) / (params->var.b * params->var.h));
	result.sprintf("%.2f",e_real_x);
	esbeltez_x_real->SetValue(result);
	
	double e_rel_x = (e_real_x / M_PI) * sqrt(params->get_mat(CPA) / (0.7 * params->get_mat(Ecs)));

	result.sprintf("%.2f", e_rel_x);
	esbeltez_x_rel->SetValue(result);
	double Kcx;
	if (e_rel_x <= 0.3f) {  //Barra Curta
		Kcx = 1;
	}
	else {
		
		double kx = 0.5 * (1+beta*(e_rel_x-0.3)+pow(e_rel_x,2));
		Kcx = 1 / (kx + sqrt(pow(kx,2) - pow(e_rel_x,2)));
		
	}
	result.sprintf("%.2f", Kcx);
	kcx->SetValue(result);

	double e_real_y = L * 100 / sqrt((params->var.h * pow(params->var.b, 3) / 12) / (params->var.b * params->var.h));
	result.sprintf("%.2f", e_real_y);
	esbeltez_y_real->SetValue(result);

	double e_rel_y = (e_real_y / M_PI) * sqrt(params->get_mat(CPA) / ( 0.7 * params->get_mat(Ecs)));
				;
	result.sprintf("%.2f", e_rel_y);
	esbeltez_y_rel->SetValue(result);
	double Kcy;
	if (e_rel_y <= 0.3f) {  //Barra Curta
		Kcy = 1;
	}
	else {
		double ky = 0.5 * (1 + beta * (e_rel_y - 0.3) + pow(e_rel_y, 2));
		Kcy = 1 / (ky + sqrt(pow(ky, 2) - pow(e_rel_y, 2)));
	}
	result.sprintf("%.2f", Kcy);
	kcy->SetValue(result);

	double KC = (Kcx < Kcy) ? Kcx : Kcy; // Obter Kc do eixo crítico
	double kmod_to = params->get_KMOD();
	double res = KC * (kmod_to / params->var.gama_w[0]) * (params->var.b * params->var.h) * params->get_mat(CPA) * 10.1972;
	result.sprintf("Nr = %.2f kgf", res);
	
	if (res >= abs(params->var.normal)) {
			resultado_comp->SetForegroundColour(0x0000FF00);
			result.sprintf("%s > N = %.3f kgf (OK!)", result, abs(params->var.normal));
	}
	if (res < abs(params->var.normal)) {
			resultado_comp->SetForegroundColour(0x000000FF);
			result.sprintf("%s < N = %.3f kgf (Ruptura!)", result, abs(params->var.normal));
	}
	
	resultado_comp->SetLabelText(result);
	

}
void RetanguloParams::calcular_tracao(wxCommandEvent& evt) {
	wxString form = "";
	CalcParams* params = CalcParams::getInstance();
	double area_bruta;
	//Verificar se existe uma seção transversal
	if (params->var.b * params->var.h == 0) {
		wxMessageBox("É necessário definir as dimensões da seção transversal", "Erro", wxOK | wxICON_ERROR);
		return;
	}
	area_bruta = params->var.b * params->var.h;

	double kmod_to = params->get_KMOD();

	double e =0, N = 0, area_liquida;
	diametro_furos->GetValue().ToCDouble(&e);
	num_furos->GetValue().ToCDouble(&N);
	
	area_liquida = area_bruta - (e/10) * params->var.b * N;
	if (area_liquida <= 0 ) {
		wxMessageBox("Dimensões de furo/entalhe inconsistentes com a seção.", "Erro", wxOK | wxICON_ERROR);
		return;
	}
	if (resultado_trac == nullptr) {
		resultado_trac = new wxStaticText(panel_tracao, wxID_ANY, form);
		resultado_trac->SetFont(*params->var.fonte_resultado);
		v_al_1->Insert(2, resultado_trac);
		v_al_1->AddSpacer(30);
		st_1->Layout();
	}
	//NBR 7190/22 Tensão resistente de tração é a tensão máxima de compressao paralela as fibras (CPA)
	double res = area_liquida * 
				 ( kmod_to / params->var.gama_w[2]) *  //phic
				 params->get_mat(CPA) * 10;
	
	if (params->var.met_calc & 0xFF) {
		form.sprintf("Tr = %.3f kgf (NBR 7190/22)", res);
	}
	if (params->var.met_calc & 0xFF00) {
		res *= 1.3;
		form.sprintf("Tr = %.3f kgf (NBR 7190/97)", res);
	}
	if (params->var.met_calc & 0xFF0000) {
		res = area_liquida * (kmod_to / params->var.gama_w[2]) *  params->get_mat(MOR) * 10.1972;
		form.sprintf("Tr = %.3f kgf (NBR 7190/82)", res);
	}
	if (params->var.normal > 0) {
		if (res > params->var.normal) {
			resultado_trac->SetForegroundColour(0x0000FF00);
			form.sprintf("%s > N = %.3f kgf (OK!)", form, params->var.normal);
		}
		if (res < params->var.normal) {
			resultado_trac->SetForegroundColour(0x000000FF);
			form.sprintf("%s > N = %.3f kgf (Ruptura!)", form, params->var.normal);
		}
	}
	resultado_trac->SetLabelText(form);
	
}
RetanguloParams::~RetanguloParams() {
	
}
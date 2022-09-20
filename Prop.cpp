#include "Prop.h"
Prop::Prop(wxWindow* pai, int op) : wxPanel(pai, wxID_ANY, wxDefaultPosition, wxSize(300, -1)), op_w{ op } {
	switch (op) {
	case ABRIR_MADEIRA:
		show_madeira();
		break;
	case ABRIR_SECAO:
		show_secao();
		break;
	case ABRIR_CARREGAMENTO:
		show_carregamento();
		break;
	}
	
}
void Prop::show_secao() {
	SetBackgroundColour(wxColour(0x00FAFAFA));
	bs_secao = new wxBoxSizer(wxVERTICAL);
	secao = new wxStaticBoxSizer(wxVERTICAL, this, "Seção Transversal");
	secao->AddSpacer(20);
	secao->Add(new wxStaticText(this, wxID_ANY, "Geometria da seção"),0,wxCENTER,0);
	secao->AddSpacer(10);
	const char* a[] = { "Retangular Simples", "Retangular Composta Dupla", "Retangular Composta Tripla","Circular", };
	
	cb_geometria_secao = new wxComboBox(this, wxID_ANY,a[0], wxPoint(-1, -1), wxSize(300, 30),
		wxArrayString(4, a), wxCB_READONLY);
	cb_geometria_secao->Bind(wxEVT_COMBOBOX,&Prop::cb_secao,this);
	secao->Add(cb_geometria_secao,0,wxCENTER,0);
	cb_geometria_secao->SetSelection(CalcParams::getInstance()->var.tipo_select);

	update_secao (CalcParams::getInstance()->var.tipo_select);
	secao->AddSpacer(10);
	bs_secao->Add(secao, 1, wxEXPAND | wxALL, 10);
	SetSizer(bs_secao);
}
void Prop::update_secao(int e) {
	switch (e) {
	case 0:
		ret_form = new RetanguloForm(this);
		p_class[0] = ret_form;
		secao->Add(ret_form, 0, wxCENTER, 0);
		break;
	case 1:
		ret2_form = new Retangulo2Form(this);
		p_class[1] = ret2_form;
		secao->Add(ret2_form, 0, wxCENTER, 0);
		break;
	case 2:

		break;
	case 3:

		break;
	}
}
void Prop::cb_secao(wxCommandEvent& evt) {
	CalcParams* params = CalcParams::getInstance();
	
	int e = evt.GetSelection();
	if (p_class[params->var.tipo_select] != nullptr) {
		delete p_class[params->var.tipo_select];
		p_class[params->var.tipo_select] = nullptr;
	}
	update_secao(e);
	secao->Layout();
	params->var.tipo_select = evt.GetSelection();
	Params::getInstance(nullptr)->update();
}
void Prop::alterado_carregamento(wxCommandEvent& evt) {
	CalcParams* params = CalcParams::getInstance();
	double valor = 0;
	NumCtrl* obj = reinterpret_cast <NumCtrl*>(evt.GetEventObject());
	obj->GetValue().ToCDouble(&valor);
	if (obj == normal) {
		params->var.normal = valor;
	}
	if (obj== momento_x) {
		params->var.momentox = valor;
	}
	if (obj == momento_y) {
		params->var.momentoy = valor;
	}
	if (obj == cisalhamento) {
		params->var.cisalhamento = valor;
	}
	evt.Skip();
}
void Prop::show_carregamento() {
	SetBackgroundColour(wxColour(0x00FAFAFA));
	bs_carregamento = new wxBoxSizer(wxVERTICAL);
	wxStaticBoxSizer *carregamento = new wxStaticBoxSizer(wxVERTICAL, this, "Carregamento na seção");
	carregamento->AddSpacer(20);
	CalcParams* params = CalcParams::getInstance();
	wxBoxSizer* hn = new wxBoxSizer(wxHORIZONTAL);
	wxString stored;
	stored.sprintf("%.3f", params->var.normal);
	normal = new NumCtrl(this, wxID_ANY, stored, wxDefaultPosition, wxSize(80, 20), wxTE_CENTER|POSITIVO_APENAS);
	normal->setCasasDecimais(3);
	normal->Bind(wxEVT_TEXT, &Prop::alterado_carregamento, this);
	hn->Add(new wxStaticText(this, wxID_ANY, "N:", wxDefaultPosition, wxSize(30, 20)));
	hn->AddSpacer(10);
	hn->Add(normal);
	hn->AddSpacer(10);
	hn->Add(new wxStaticText(this, wxID_ANY, "kgf", wxDefaultPosition, wxSize(30, 20)));
	

	wxBoxSizer* hmx = new wxBoxSizer(wxHORIZONTAL);
	stored.sprintf("%.3f", params->var.momentox);
	momento_x = new NumCtrl(this, wxID_ANY, stored, wxDefaultPosition, wxSize(80, 20), wxTE_CENTER);
	momento_x->setCasasDecimais(3);
	momento_x->Bind(wxEVT_TEXT, &Prop::alterado_carregamento, this);
	hmx->Add(new wxStaticText(this,wxID_ANY,"Msx:",wxDefaultPosition,wxSize(30,20)));
	hmx->AddSpacer(10);
	hmx->Add(momento_x);
	hmx->AddSpacer(10);
	hmx->Add(new wxStaticText(this, wxID_ANY, "kgf.m",wxDefaultPosition,wxSize(30,20)));

	wxBoxSizer* hmy = new wxBoxSizer(wxHORIZONTAL);
	stored.sprintf("%.3f", params->var.momentoy);
	momento_y = new NumCtrl(this, wxID_ANY, stored, wxDefaultPosition, wxSize(80, 20), wxTE_CENTER);
	momento_y->setCasasDecimais(3);
	momento_y->Bind(wxEVT_TEXT, &Prop::alterado_carregamento, this);
	hmy->Add(new wxStaticText(this, wxID_ANY, "Msy:", wxDefaultPosition, wxSize(30, 20)));
	hmy->AddSpacer(10);
	hmy->Add(momento_y);
	hmy->AddSpacer(10);
	hmy->Add(new wxStaticText(this, wxID_ANY, "kgf.m", wxDefaultPosition, wxSize(30, 20)));

	wxBoxSizer* hcis = new wxBoxSizer(wxHORIZONTAL);
	stored.sprintf("%.3f", params->var.cisalhamento);
	cisalhamento = new NumCtrl(this, wxID_ANY,stored, wxDefaultPosition, wxSize(80, 20), wxTE_CENTER);
	cisalhamento->setCasasDecimais(3);
	cisalhamento->Bind(wxEVT_TEXT, &Prop::alterado_carregamento, this);
	hcis->Add(new wxStaticText(this, wxID_ANY, "V:", wxDefaultPosition, wxSize(30, 20)));
	hcis->AddSpacer(10);
	hcis->Add(cisalhamento);
	hcis->AddSpacer(10);
	hcis->Add(new wxStaticText(this, wxID_ANY, "kgf", wxDefaultPosition, wxSize(30, 20)));


	carregamento->Add(hn,0,wxALIGN_CENTER,0);
	carregamento->AddSpacer(10);
	carregamento->Add(hmx, 0, wxALIGN_CENTER, 0);
	carregamento->AddSpacer(10);
	carregamento->Add(hmy, 0, wxALIGN_CENTER, 0);
	carregamento->AddSpacer(10);
	carregamento->Add(hcis, 0, wxALIGN_CENTER, 0);
	carregamento->AddSpacer(10);
	bs_carregamento->Add(carregamento, 1, wxEXPAND | wxALL, 10);
	SetSizer(bs_carregamento);
}
void Prop::show_madeira() {
	SetBackgroundColour(wxColour(0x00FAFAFA));
	bs_madeira = new wxBoxSizer(wxVERTICAL);
	wxStaticBoxSizer* madeira = new wxStaticBoxSizer(wxVERTICAL, this, "Madeira");
	
	const char* a[] = { "Seca","Verde" };
	radio_m = new wxRadioBox(this, wxID_ANY, "Condição", wxPoint(-1, -1), wxSize(-1, -1), wxArrayString(2, a), 0, 0);
	radio_m->SetSelection(CalcParams::getInstance()->var.condicao_mad);

	radio_m->Bind(wxEVT_RADIOBOX, &Prop::radio_condicao, this);
	madeira->AddSpacer(20);
	madeira->Add(radio_m,0,wxEXPAND);
	madeira->AddSpacer(10);

	//Selecionar a especie
	wxBoxSizer* esp =new wxBoxSizer(wxHORIZONTAL);
	wxBitmap* bmp_mais = new wxBitmap("res\\mais.bmp", wxBITMAP_TYPE_BMP);
	wxMask* mask_mais = new wxMask(*bmp_mais, wxColour(0xFFFFFFFF));
	bmp_mais->SetMask(mask_mais);
	adicionar = new wxBitmapButton(this, wxID_ANY, wxBitmapBundle(*bmp_mais));
	adicionar->Bind(wxEVT_BUTTON, &Prop::adicionar_madeira, this);
	esp->Add(new wxStaticText(this, wxID_ANY, "Nome da espécie"));
	esp->Add(adicionar, 0, wxLEFT, 155);
	buscar_madeira = new wxSearchCtrl(this, wxID_ANY,wxEmptyString,wxDefaultPosition,wxSize(300,-1));
	CalcParams* params = CalcParams::getInstance();
	if(params->var.lista_nome_cientifico.IsEmpty()) {
		ler_lista_de_madeira(params->var.lista_nome_cientifico,
						       params->var.lista_densidade_basica,
							 params->var.lista_nome_popular,
						  "res\\ListaMadeira.csv");
		params->var.index_db = 0;
	}
	buscar_madeira->AutoComplete(params->var.lista_nome_cientifico);
	buscar_madeira->SetValue(params->var.lista_nome_cientifico[params->var.index_db]);
	buscar_madeira->Bind(wxEVT_COMMAND_TEXT_UPDATED, &Prop::update_dados, this);
	madeira->Add(esp);
	madeira->AddSpacer(10);
	madeira->Add(buscar_madeira, 0, wxCENTER, 0);
	madeira->AddSpacer(10);

	//Tipo de Madeira
	madeira->Add(new wxStaticText(this, wxID_ANY, "Tipo de madeira"));
	madeira->AddSpacer(10);
	const char* b[] = { "Serrada, laminada colada ou compensada", "Recomposta" };
	cb_tipo_madeira = new wxComboBox(this, wxID_ANY, b[0], wxPoint(-1, -1), wxSize(300, 30),
		wxArrayString(2, b), wxCB_READONLY);

	cb_tipo_madeira->Bind(wxEVT_COMBOBOX, &Prop::cb_madeira,this);
	madeira->Add(cb_tipo_madeira);
	madeira->AddSpacer(10);

	//Classe de carregamento
	madeira->Add(new wxStaticText(this, wxID_ANY, "Classe de carregamento"));
	madeira->AddSpacer(10);
	const char* c[] = { "Permanente", "Longa Duração","Média duração","Curta duração", "Instantânea"};
	cb_classe_carregamento = new wxComboBox(this, wxID_ANY, c[0], wxPoint(-1, -1), wxSize(300, 30),
		wxArrayString(5, c), wxCB_READONLY);
	
	cb_classe_carregamento->Bind(wxEVT_COMBOBOX, &Prop::cb_madeira, this);
	madeira->Add(cb_classe_carregamento);
	madeira->AddSpacer(10);


	//Classe de Umidade do Ambiente
	madeira->Add(new wxStaticText(this, wxID_ANY, "Classe de umidade do ambiente"));
	madeira->AddSpacer(10);
	const char* d[] = { "Umad < 15%, Uamb < 75% (1 e 2)", "Umad > 15%, Uamb > 75% (3 e 4)" };
	cb_classe_umidade = new wxComboBox(this, wxID_ANY, d[0], wxPoint(-1, -1), wxSize(300, 30),
		wxArrayString(2, d),wxCB_READONLY);
	cb_classe_umidade->Bind(wxEVT_COMBOBOX, &Prop::cb_madeira, this);
	madeira->Add(cb_classe_umidade);
	madeira->AddSpacer(10);

	//Categoria
	madeira->Add(new wxStaticText(this, wxID_ANY, "Categoria da madeira"));
	madeira->AddSpacer(10);
	const char* e[] = { "Primeira categoria", "Segunda Categoria" };
	cb_categoria = new wxComboBox(this, wxID_ANY, e[0], wxPoint(-1, -1), wxSize(300, 30),
		wxArrayString(2, e), wxCB_READONLY);
	cb_categoria->Bind(wxEVT_COMBOBOX, &Prop::cb_madeira, this);
	madeira->Add(cb_categoria);
	madeira->AddSpacer(10);


	/************************************* KMOD's *******************************/
		//Kmod1		
	wxBitmap* kmod1_bmp = new wxBitmap("res\\kmod1.bmp", wxBITMAP_TYPE_BMP);
	wxMask* kmod1_mask = new wxMask(*kmod1_bmp, wxColour(0xFFFFFFFF));
	kmod1_bmp->SetMask(kmod1_mask);

	wxStaticBitmap* kmod1_label = new wxStaticBitmap(this,wxID_ANY, wxBitmapBundle(*kmod1_bmp));
	kmod1 = new NumCtrl(this,10004,"0.6",wxDefaultPosition,wxSize(50,20),wxTE_CENTER|wxTE_READONLY);
	wxBoxSizer* kmod_v_1 = new wxBoxSizer(wxVERTICAL);
	kmod_v_1->Add(kmod1_label);
	kmod_v_1->Add(kmod1);
		//Kmod2		
	wxBitmap* kmod2_bmp = new wxBitmap("res\\kmod2.bmp", wxBITMAP_TYPE_BMP);
	wxMask* kmod2_mask = new wxMask(*kmod2_bmp, wxColour(0xFFFFFFFF));
	kmod2_bmp->SetMask(kmod2_mask);

	wxStaticBitmap* kmod2_label = new wxStaticBitmap(this, wxID_ANY, wxBitmapBundle(*kmod2_bmp));
	kmod2 = new NumCtrl(this, 10005, "1.0", wxDefaultPosition, wxSize(50, 20), wxTE_CENTER | wxTE_READONLY);
	
	wxBoxSizer* kmod_v_2 = new wxBoxSizer(wxVERTICAL);
	kmod_v_2->Add(kmod2_label);
	kmod_v_2->Add(kmod2);
		//Kmod3		
	wxBitmap* kmod3_bmp = new wxBitmap("res\\kmod3.bmp", wxBITMAP_TYPE_BMP);
	wxMask* kmod3_mask = new wxMask(*kmod3_bmp, wxColour(0xFFFFFFFF));
	kmod3_bmp->SetMask(kmod3_mask);

	wxStaticBitmap* kmod3_label = new wxStaticBitmap(this, wxID_ANY, wxBitmapBundle(*kmod3_bmp));
	kmod3 = new NumCtrl(this, 10006, "0.8", wxDefaultPosition, wxSize(50, 20), wxTE_CENTER | wxTE_READONLY);
	wxBoxSizer* kmod_v_3 = new wxBoxSizer(wxVERTICAL);
	kmod_v_3->Add(kmod3_label);
	kmod_v_3->Add(kmod3);
		//Kmod
	wxBitmap* kmod_bmp = new wxBitmap("res\\kmod.bmp", wxBITMAP_TYPE_BMP);
	wxMask* kmod_mask = new wxMask(*kmod_bmp, wxColour(0xFFFFFFFF));
	kmod_bmp->SetMask(kmod_mask);

	wxStaticBitmap* kmod_label = new wxStaticBitmap(this, wxID_ANY, wxBitmapBundle(*kmod_bmp));
	kmod = new NumCtrl(this, 10007, "", wxDefaultPosition, wxSize(50, 20), wxTE_CENTER|wxTE_READONLY);
	wxBoxSizer* kmod_v = new wxBoxSizer(wxVERTICAL);
	kmod_v->Add(kmod_label);
	kmod_v->Add(kmod);

	wxBoxSizer* kmod_h = new wxBoxSizer(wxHORIZONTAL);
	kmod_h->Add(kmod_v_1);
	kmod_h->AddSpacer(20);
	kmod_h->Add(kmod_v_2); 
	kmod_h->AddSpacer(20);
	kmod_h->Add(kmod_v_3);
	kmod_h->AddSpacer(20);
	kmod_h->Add(kmod_v);

	madeira->Add(kmod_h);
	/******************************************************************/
	update_field_madeira();
	bs_madeira->Add(madeira, 1, wxEXPAND | wxALL, 10);
	SetSizer(bs_madeira);
}
void Prop::adicionar_madeira(wxCommandEvent& evt) {
	CalcParams* params = CalcParams::getInstance();
	if (am == nullptr) {
		am = new AdicionarMadeira(this);
	}
	if (am->ShowModal()) {
		ler_lista_de_madeira(params->var.lista_nome_cientifico,
			params->var.lista_densidade_basica,
			params->var.lista_nome_popular,
			"res\\ListaMadeira.csv");
		buscar_madeira->AutoComplete(params->var.lista_nome_cientifico);
		buscar_madeira->SetValue(params->var.lista_nome_cientifico[params->var.index_db]);
	}
}
void Prop::radio_condicao(wxCommandEvent &evt){
	CalcParams::getInstance()->var.condicao_mad = evt.GetSelection();
	evt.Skip();
}
void Prop::cb_madeira(wxCommandEvent& evt) {

	int i=0;
	if (evt.GetEventObject() == cb_classe_carregamento) {
		i = 1;
	}
	if (evt.GetEventObject() == cb_classe_umidade) {
		i = 2;
	}
	if (evt.GetEventObject() == cb_categoria) {
		i = 3;
	}
	CalcParams::getInstance()->var.kmod_select[i] = evt.GetSelection();
	update_field_madeira();
	evt.Skip();
}
void Prop::update_dados(wxCommandEvent& evt) {
	CalcParams* param = CalcParams::getInstance();
	int index = param->var.lista_nome_cientifico.Index(evt.GetString(), false);
	if (index == wxNOT_FOUND) {
		return;
	}
	param->var.index_db = index;
}
void Prop::update_field_madeira() {
	 

	int a = CalcParams::getInstance()->var.kmod_select[0];
	int b = CalcParams::getInstance()->var.kmod_select[1];
	int c = CalcParams::getInstance()->var.kmod_select[2];
	int d = CalcParams::getInstance()->var.kmod_select[3];
	int e = CalcParams::getInstance()->var.condicao_mad;
	
	radio_m->SetSelection(e);
	cb_tipo_madeira->SetSelection(a);
	cb_classe_carregamento->SetSelection(b);
	cb_classe_umidade->SetSelection(c);
	cb_categoria->SetSelection(d);

	wxString parse;
	parse.sprintf("%.2f", CalcParams::getInstance()->var.kmod1_norma[b][a]);
	kmod1->SetValue(parse);
	parse.sprintf("%.2f", CalcParams::getInstance()->var.kmod2_norma[c][a]);
	kmod2->SetValue(parse);
	parse.sprintf("%.2f", CalcParams::getInstance()->var.kmod3_norma[d]);
	kmod3->SetValue(parse);
	double kmod_to = CalcParams::getInstance()->get_KMOD();
	parse.sprintf("%.2f", kmod_to);
	kmod->SetValue(parse);

}
bool Prop::ler_lista_de_madeira(wxArrayString &lista_nome_cientifico, wxArrayDouble&lista_densidade_basica, wxArrayString &lista_nome_popular, wxString path) const {
	wxFile* file = new wxFile(path,wxFile::read);
	if (file->Error()) {
		wxMessageBox("Não foi possível abrir a lista de madeiras.", "Erro", wxOK | wxICON_EXCLAMATION);
		return false;
	}
	wxString nome_cientifico, nome_popular, densidade_basica;
	int index = 1;			//Primeira coluna
	char c;
	double val;
	for (; !file->Eof();) {
		file->Read(&c,sizeof(c));
		if (c == ';') {
			switch (index) {
			case 1:
				lista_nome_cientifico.Add(nome_cientifico);
				nome_cientifico.Clear();
				break;
			case 2:
				lista_nome_popular.Add(nome_popular);
				nome_popular.Clear();
				break;
			case 9:
				if (densidade_basica.ToCDouble(&val)) {
					lista_densidade_basica.Add(val);
					densidade_basica.Clear();
				}
				else {
					wxMessageBox("Não foi possível ler o arquivo", "Erro", wxOK | wxICON_ERROR);
					return false; 
				}
				break;
			}
			index++;
			continue;
		}
		if (c == '\r') {
			file->Read(&c, sizeof(c));
			index = 1;
			continue;
		}

		switch (index) {
		case 1:
			nome_cientifico.append(c);
			break;
		case 2:
			nome_popular.append(c);
			break;
		case 9:
			densidade_basica.append(c);
			break;
		}
		
	}
	return file->Close();
	
}
Prop::~Prop() {
	 

}
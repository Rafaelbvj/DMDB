#include "MainForm.h"
MainForm::MainForm() : wxFrame(nullptr, wxID_ANY, "DMBD", wxPoint(0, 0), wxSize(900, 650), wxDEFAULT_FRAME_STYLE, "") {
	SetBackgroundColour(wxColour(0x00FFFFFF));
	calc = CalcParams::getInstance();
	nr = new NormaReferencia(this);
	pn = Params::getInstance(this);
	sp = new Prop(this,ABRIR_MADEIRA);
	mod = new Modelo(this);
	//Toolbar
	tb = CreateToolBar(wxTB_HORIZONTAL,-1,"TB_1");
	wxBitmap* bmp = new wxBitmap("res\\a.bmp", wxBITMAP_TYPE_BMP);
	wxBitmap* bmp2 = new wxBitmap("res\\b.bmp", wxBITMAP_TYPE_BMP);
	wxBitmap* bmp3 = new wxBitmap("res\\c.bmp", wxBITMAP_TYPE_BMP);
	wxMask* mask = new wxMask(wxBitmap("res\\a.bmp", wxBITMAP_TYPE_BMP), wxColour(0xFFFFFFFF));
	wxMask* mask2 = new wxMask(wxBitmap("res\\b.bmp", wxBITMAP_TYPE_BMP), wxColour(0xFFFFFFFF));
	wxMask* mask3 = new wxMask(wxBitmap("res\\c.bmp", wxBITMAP_TYPE_BMP), wxColour(0xFFFFFFFF));
	bmp3->SetMask(mask3);
	bmp2->SetMask(mask2);
	bmp->SetMask(mask);
	tb->AddTool(10003, "", wxBitmapBundle(*bmp2), wxString("Editar madeira"), wxITEM_RADIO);
	tb->AddTool(10002, "", wxBitmapBundle(*bmp),wxString("Editar seção"),wxITEM_RADIO);
	tb->AddTool(10004, "", wxBitmapBundle(*bmp3), wxString("Editar solicitações"), wxITEM_RADIO);
	tb->Bind(wxEVT_TOOL,&MainForm::tool_bt,this);
	tb->Realize();

	//Adiciona painel de propriedades e formulario de calculo
	bs_lc = new wxBoxSizer(wxHORIZONTAL);
	bs_lc->Add(pn, 1,wxEXPAND);
	bs_lc->Add(sp, 0, wxEXPAND);
	SetSizer(bs_lc);

	//Menu
	wxMenuBar* mb = new wxMenuBar();
	wxMenu* menu = new wxMenu();
	menu->Append(new wxMenuItem(menu, 10005, "Norma de Referência"));
	menu->Append(new wxMenuItem(menu, 10017, "Modelo"));
	mb->Append(menu,wxString("Configurações"));
	SetMenuBar(mb);
	mb->Bind(wxEVT_MENU, &MainForm::menu_evt, this);
}
void MainForm::menu_evt(wxCommandEvent& evt) {
	
	switch (evt.GetId()) {
	case 10005:
		nr->ShowModal();
		break;
	case 10017:
		mod->ShowModal();
		break;
	}
	
}
void MainForm::tool_bt(wxCommandEvent& evt) {
	bs_lc->Remove(1);
	delete sp;
	switch (evt.GetId()) {
		case 10002:
			
			sp = new Prop(this, ABRIR_SECAO);

			break;
		case 10003:
			
			sp = new Prop(this, ABRIR_MADEIRA);
	 
			break;
		case 10004:
			sp = new Prop(this, ABRIR_CARREGAMENTO);

			break;
	}
	bs_lc->Insert(1, sp, 0, wxEXPAND);
	bs_lc->Layout();
	
}
MainForm::~MainForm() {

}

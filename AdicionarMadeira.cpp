#include "AdicionarMadeira.h"
AdicionarMadeira::AdicionarMadeira(wxWindow* pai) :wxDialog(pai,wxID_ANY,"Nova Madeira",wxDefaultPosition,wxSize(250,320)) {
	wxBoxSizer* bs = new wxBoxSizer(wxVERTICAL);
	st = new wxStaticBoxSizer(wxVERTICAL,this,"Informações da madeira");
	st->AddSpacer(20);
	st->Add(new wxStaticText(this, wxID_ANY, "Nome científico da madeira:"));
	st->AddSpacer(10);
	nome_cientifico = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition,wxSize(200,20));
	st->Add(nome_cientifico);

	st->AddSpacer(10);
	st->Add(new wxStaticText(this, wxID_ANY, "Nome popular da madeira (opcional):"));
	st->AddSpacer(10);
	nome_popular = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200, 20));
	st->Add(nome_popular);

	st->AddSpacer(10);
	st->Add(new wxStaticText(this, wxID_ANY, "Densidade básica da madeira (g/cm³):"));
	st->AddSpacer(10);
	densidade_basica = new NumCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200, 20), POSITIVO_APENAS);
	densidade_basica->setCasasDecimais(4);
	st->Add(densidade_basica);
	bs->AddSpacer(20);
	bs->Add(st, 0, wxALIGN_CENTER,0);
	bs->AddSpacer(20);
	salvar = new wxButton(this, 10026, "Salvar no banco", wxDefaultPosition, wxSize(-1, 30));
	salvar->Bind(wxEVT_BUTTON, &AdicionarMadeira::salvar_banco, this);
	bs->Add(salvar,0,wxALIGN_CENTER,0);
	SetSizer(bs);
}
int AdicionarMadeira::ShowModal()  {
	salvo = false;
	wxDialog::ShowModal();
	return salvo;
}
void AdicionarMadeira::salvar_banco(wxCommandEvent& evt) {
	wxString nome_c = nome_cientifico->GetValue();
	wxString nome_p = nome_popular->GetValue();
	wxString db = densidade_basica->GetValue();
	CalcParams* params = CalcParams::getInstance();
	if (nome_c == wxEmptyString) {
		wxMessageBox("Insira nome cientifico da madeira.", "Erro", wxOK | wxICON_ERROR);
		return;
	}
	if (db == wxEmptyString) {
		wxMessageBox("Insira densidade básica da madeira.", "Erro", wxOK | wxICON_ERROR);
		return;
	}
	adicionar_lista("res/ListaMadeira.csv", nome_c, nome_p, db);
	salvo = true;
	wxMessageBox("Salvo!");
}
void AdicionarMadeira::adicionar_lista(wxString path, wxString& nome_c, wxString& nome_p, wxString& db) {
	wxFile* file = new wxFile(path, wxFile::write_append);
	if (!file->IsOpened()) {

		return;
	}
	wxString data;
	data.sprintf("%s;%s;;;;;;;%s;;;;;;;;;;;;;;;;;;;;;;;\r\n", nome_c, nome_p, db);
	file->Write(data);
	file->Close();
	
}
AdicionarMadeira::~AdicionarMadeira() {

}
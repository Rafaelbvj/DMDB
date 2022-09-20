#pragma once
#include <wx/wx.h>
#include <wx/notebook.h>
#include <wx/srchctrl.h>
#include <wx/xrc/xh_all.h>
#include "Params.h"
#include "RetanguloForm.h"
#include "NumCtrl.h"
#include "CalcParams.h"
#include "AdicionarMadeira.h"
#include "Retangulo2Form.h"
#define ABRIR_MADEIRA 1
#define ABRIR_SECAO 2
#define ABRIR_CARREGAMENTO 3
class Prop: public wxPanel
{
private:
	int op_w;
	wxPanel* p_class[5] ={nullptr,nullptr,nullptr,nullptr};
	//Componentes da aba madeira
	wxBoxSizer* bs_madeira;
	wxSearchCtrl* buscar_madeira;
	NumCtrl* kmod1,*kmod2,*kmod3, *kmod;
	wxComboBox* cb_classe_umidade, *cb_classe_carregamento, *cb_tipo_madeira, *cb_categoria;
	wxComboBox* cb_geometria_secao;
	wxRadioBox* radio_m;
	wxBitmapButton* adicionar = nullptr;
	AdicionarMadeira* am = nullptr;
	//Componentes da aba secao
	wxBoxSizer* bs_secao;
	wxStaticBoxSizer* secao;
	RetanguloForm* ret_form = nullptr;
	Retangulo2Form* ret2_form = nullptr;
	//CirculoForm* cir_form;

	//Componentes da aba carregamento
	wxBoxSizer* bs_carregamento;
	NumCtrl *normal, * momento_x, *momento_y, * cisalhamento;
	//
	void update_secao(int);
	void alterado_carregamento(wxCommandEvent&);
	void cb_madeira(wxCommandEvent&);
	void cb_secao(wxCommandEvent&);
	void radio_condicao(wxCommandEvent&);
	void update_dados(wxCommandEvent&);
	void show_secao();
	void show_carregamento();
	void adicionar_madeira(wxCommandEvent&);
	void show_madeira();
	void update_field_madeira();
	bool ler_lista_de_madeira(wxArrayString&, wxArrayDouble&, wxArrayString&, wxString) const;
public:
	Prop(wxWindow *, int);
	~Prop();
	

};


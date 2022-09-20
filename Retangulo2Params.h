#pragma once
#include <wx/wx.h>
#include <wx/notebook.h>
#include "CalcParams.h"
#include "NumCtrl.h"
class Retangulo2Params : public wxNotebook
{
private:

	wxBoxSizer* bs;
	wxBoxSizer *st_1, * st_2, * st_3, * st_4, * st_4_1, * st_5;
	//Tração
	wxPanel* panel_tracao;
	wxBoxSizer* h_al_1;
	wxBoxSizer* v_al_1;
	NumCtrl* num_furos;
	NumCtrl* diametro_furos;
	NumCtrl* gama_w;
	wxStaticText* resultado_trac = nullptr;
	wxButton* t_calc;
	//Compressão
	wxPanel* panel_comp;
	wxRadioBox* beta_r, *tipo_separador, *tipo_junc;
	NumCtrl* comprimento_barra, *distancia_esp;
	wxButton* c_calc;
	wxBoxSizer* h_al_2, * v_al_2_1;
	wxStaticText* resultado_comp;
	wxStaticBitmap* comp_bmp;
	wxBitmap* comp_ret_esp, * comp_ret_ch;
	//Eixo X
	wxStaticBoxSizer* eixo_x = nullptr;
	wxTextCtrl* esbeltez_x_real;
	wxTextCtrl* esbeltez_x_rel;
	wxTextCtrl* kcx;
	//Eixo Y
	wxStaticBoxSizer* eixo_y = nullptr;
	wxTextCtrl* esbeltez_y_real;
	wxTextCtrl* esbeltez_y_ficticia;
	wxTextCtrl* esbeltez_y_rel;
	wxTextCtrl* kcy;
	//Flexão
	wxPanel* panel_flexao;
	wxButton* f_calc;
	wxBoxSizer* v_al_3;
	wxStaticText* resultado_flexao_x = nullptr;
	wxStaticText* resultado_flexao_y = nullptr;
	wxBoxSizer* h_al_3, * h_al_3_b;
	//Flexão Oblíqua
	wxPanel* panel_flexao_obliqua;
	wxTextCtrl* ms_x, * ms_y;
	wxTextCtrl* r_x, * r_y;
	wxButton* c_x, * c_y;
	wxBoxSizer* v_al_5;
	wxButton* fc_calc;
	wxStaticText* resultado_flexao_tracao = nullptr;
	//Cisalhamento
	wxPanel* panel_cis;
	wxBoxSizer* v_al_6;
	wxBoxSizer* h_cis_v;
	wxButton* cis_calc;
	wxStaticText* resultado_cis = nullptr;
	void desabilitar_parafusado(wxCommandEvent&);
public:
	Retangulo2Params(wxWindow*);
	void calcular_fo_mr(wxCommandEvent&);
	void calcular_cis(wxCommandEvent&);
	void calcular_tracao(wxCommandEvent&);
	void calcular_comp(wxCommandEvent&);
	void calcular_flexao(wxCommandEvent&);
	void calcular_flexao_obliqua(wxCommandEvent&);
	~Retangulo2Params();

};


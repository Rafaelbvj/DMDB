#pragma once
#include <wx/wx.h>
#include <wx/collpane.h>
#include "CalcParams.h"
#include "NumCtrl.h"
#include <wx/notebook.h>

class RetanguloParams : public wxNotebook
{
private:
	
	wxBoxSizer* bs;
	wxBoxSizer* st_1, * st_2 , *st_3, *st_4, *st_4_1, *st_5;
	//Tração
	wxPanel* panel_tracao;
	wxBoxSizer* h_al_1;
	wxBoxSizer* v_al_1;
	NumCtrl* num_furos;
	NumCtrl* diametro_furos;
	NumCtrl* gama_w;
	wxStaticText* resultado_trac = nullptr;
	wxButton *t_calc;
	double tracao_resistente;
	//Compressão
	wxPanel* panel_comp;
	wxRadioBox* beta_r;
	NumCtrl* comprimento_barra;
	wxButton* c_calc;
	wxBoxSizer* h_al_2,*v_al_2_1, *v_al_2;
	wxStaticText* resultado_comp;
		//Eixo X
		wxStaticBoxSizer* eixo_x = nullptr;
		wxTextCtrl* esbeltez_x_real;
		wxTextCtrl* esbeltez_x_rel;
		wxTextCtrl* kcx;
		//Eixo Y
		wxStaticBoxSizer* eixo_y = nullptr;
		wxTextCtrl* esbeltez_y_real;
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
	wxPanel* panel_flexao_composta;
	wxRadioBox* beta_r2;
	wxButton* fc_calc;
	wxBoxSizer* v_al_5;
	wxStaticText* resultado_flexao_tracao = nullptr;
	wxStaticText* resultado_flexao_comp = nullptr;
	wxStaticText* resultado_flexao_comp_inst = nullptr;
	NumCtrl* comprimento_barra2;
	//Cisalhamento
	wxPanel* panel_cis;
	wxBoxSizer*  h_cis_v;
	wxBoxSizer* v_al_6;
	wxButton* cis_calc;
	wxStaticText* resultado_cis = nullptr;

	public:
		RetanguloParams(wxWindow*);
		void calcular_cis(wxCommandEvent&);
		void calcular_tracao(wxCommandEvent&);
		void calcular_comp(wxCommandEvent&);
		void calcular_flexao(wxCommandEvent&);
		void calcular_flexao_obliqua(wxCommandEvent&);
		~RetanguloParams();

};


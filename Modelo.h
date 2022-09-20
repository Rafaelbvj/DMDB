#pragma once
#include <wx/wx.h>
#include "CalcParams.h"
#include "NumCtrl.h"
class Modelo : public wxDialog
{
private:
	wxBoxSizer* bs;
	NumCtrl* moe_b0_v, * moe_b1_v;
	NumCtrl* mor_b0_v, * mor_b1_v;
	NumCtrl* cpa_b0_v, * cpa_b1_v;
	NumCtrl* cpe_b0_v, * cpe_b1_v; 
	NumCtrl* cis_b0_v, * cis_b1_v;

	NumCtrl* moe_b0_s, * moe_b1_s;
	NumCtrl* mor_b0_s, * mor_b1_s;
	NumCtrl* cpa_b0_s, * cpa_b1_s;
	NumCtrl* cpe_b0_s, * cpe_b1_s;
	NumCtrl* cis_b0_s, * cis_b1_s;
	
	wxButton* salvar;
	void salvar_botao(wxCommandEvent&);
	void update_fields();
public:
	Modelo(wxWindow*);
	int ShowModal() override;
	~Modelo();
};

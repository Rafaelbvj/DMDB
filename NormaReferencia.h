#pragma once
#include <wx/wx.h>
#include "CalcParams.h"
class NormaReferencia: public wxDialog
{
private:
	wxRadioButton* nbr82, * nbr97, * nbr22;
	CalcParams* params;
public:
	NormaReferencia(wxWindow*);
	void salvar(wxCommandEvent&);
	~NormaReferencia();
};


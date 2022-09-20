#pragma once
#include <wx/wx.h>
#include "CalcParams.h"
#include "NumCtrl.h"
class RetanguloForm : public wxPanel
{
private:
	wxBoxSizer* bs_ret;
	NumCtrl * base, * altura;
	wxTextCtrl* area;
	wxTextCtrl* inercia_x, * inercia_y;
	wxTextCtrl* w_x, * w_y;

public:
	void alterado(wxCommandEvent&);
	RetanguloForm(wxWindow*);
	~RetanguloForm();
};


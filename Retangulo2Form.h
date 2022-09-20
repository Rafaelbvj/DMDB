#pragma once
#include <wx/wx.h>
#include "CalcParams.h"
#include "NumCtrl.h"
class Retangulo2Form : public wxPanel
{
private:
	wxBoxSizer* bs_ret;
	NumCtrl* base, * altura, *esp;
	wxTextCtrl* area;
	wxTextCtrl* inercia_x, * inercia_y;
	wxTextCtrl* w_x, * w_y;

public:
	void alterado(wxCommandEvent&);
	Retangulo2Form(wxWindow*);
	~Retangulo2Form();
};


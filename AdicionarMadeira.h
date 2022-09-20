#pragma once
#include <wx/wx.h>
#include <wx/file.h>
#include "NumCtrl.h"
#include "CalcParams.h"
class AdicionarMadeira: public wxDialog
{
private:
	wxStaticBoxSizer* st;
	wxTextCtrl* nome_cientifico, * nome_popular;
	NumCtrl* densidade_basica;
	wxButton* salvar;
	bool salvo = false;
	void salvar_banco(wxCommandEvent&);
	void adicionar_lista(wxString, wxString&, wxString&, wxString&);
public:
	int ShowModal() override;
	AdicionarMadeira(wxWindow*);
	~AdicionarMadeira();
};


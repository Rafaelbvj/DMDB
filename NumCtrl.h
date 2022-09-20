#pragma once
#include <wx/wx.h>
#define POSITIVO_APENAS 0xA000
class NumCtrl: public wxTextCtrl
{	
private:
	void somente_numeros(wxCommandEvent&);
	bool positivo = false, limite_casas = false;
	size_t casas_decimais = 0;
	public:
		 
		NumCtrl(wxWindow* , wxWindowID , const wxString& , const wxPoint &, const wxSize& , long );
		void setCasasDecimais(size_t);
		~NumCtrl();
};


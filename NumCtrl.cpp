#include "NumCtrl.h"

NumCtrl::NumCtrl(wxWindow *parent,wxWindowID id,const wxString &value,const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize, long style = 0L):
	wxTextCtrl(parent, id, value, pos, size, style ^ 0xA000){
	Bind(wxEVT_TEXT, &NumCtrl::somente_numeros,this);
	if (style & 0xA000) {
		positivo = true;
	}
}
NumCtrl::~NumCtrl() {

}

void NumCtrl::setCasasDecimais(size_t casas) {
	limite_casas = true;
	casas_decimais = casas;
}
void NumCtrl::somente_numeros(wxCommandEvent& evt) {
	
	wxString str = this->GetValue();
	long ip = this->GetInsertionPoint();
	wxString op;
	bool pontoExiste = false;
	long ondeponto;
	long k = 0;
	for (size_t i = 0; i < str.size(); i++) {
		char c = str[i];	
		op.append(c);
		if (c < '0' || c>'9') {
			if (c == '.') {
				if (!pontoExiste) {
					pontoExiste = true;
					ondeponto = i;
					continue;
				}
				
			}
				if (c == '-' && i == 0 && !positivo) {

					continue;
				}
		}
		else {

			if (!(pontoExiste && limite_casas && op.size()-ondeponto-1 > casas_decimais)) {
				continue;
			}
		}
		op.RemoveLast();
		k++;
	}
	if (op != str) {
		
		this->SetValue(op);
		this->SetInsertionPoint(ip>k?(ip-k):0);
	}
	evt.Skip();	// Pode ser usado por outro evento 
}
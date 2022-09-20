#include "CalcParams.h"
CalcParams *CalcParams::instance = nullptr;
CalcParams::CalcParams() {
	
	
	var.fonte_resultado = new wxFont(15, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD,false);
		

}
CalcParams::~CalcParams() {

}
CalcParams *CalcParams::getInstance() {
	if (instance == nullptr) {
		instance = new CalcParams();
	}
	return instance;
}
double CalcParams:: get_KMOD()const {
	int a = var.kmod_select[0];
	int b = var.kmod_select[1];
	int c = var.kmod_select[2];
	int d = var.kmod_select[3];
	double kmod_to =  var.kmod1_norma[b][a] *    //kmod1
					  var.kmod2_norma[c][a] *	 //kmod2
					  var.kmod3_norma[d];		 //kmod3

	return kmod_to;
}
double CalcParams::get_mat(const int material_prop) const {
	double prop =
		(var.condicao_mad ? var.coeficientes_verde[material_prop][0] : var.coeficientes_seca[material_prop][0]) *
		 var.lista_densidade_basica[var.index_db] +
		(var.condicao_mad ? var.coeficientes_verde[material_prop][1] : var.coeficientes_seca[material_prop][1])
		;
	return prop;
}
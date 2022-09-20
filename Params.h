#pragma once
#include <wx/wx.h>
#include "RetanguloParams.h"
#include "Retangulo2Params.h"
#include "CalcParams.h"
class Params : public wxScrolledWindow {
private:
	RetanguloParams* rp;
	Retangulo2Params* rp2;
	wxBoxSizer* bs;
	static Params* params;
	Params(wxWindow*);
public:
	static Params* getInstance(wxWindow*);

	void update();
	~Params();
};


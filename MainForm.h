#pragma once
#include <wx/wx.h>
#include <wx/listctrl.h>
#include "Params.h"
#include "Modelo.h"
#include "Prop.h"
#include "CalcParams.h"
#include "NormaReferencia.h"
class MainForm : public wxFrame {
private:
	Params* pn;
	Prop* sp;
	wxToolBar* tb;
	wxBoxSizer* bs_lc;
	CalcParams* calc = nullptr;
	NormaReferencia* nr;
	Modelo* mod;
public:
	MainForm();
	~MainForm();
	void OnResize(wxSizeEvent&);
	void tool_bt(wxCommandEvent&);
	void menu_evt(wxCommandEvent&);
};


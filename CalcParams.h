#pragma once
#include <wx/wx.h>
enum PARAMS_DB {
	CPA,
	MOR,
	Ecs,
	MOE,
	CPE,
	CIS
};
typedef struct info {
	/****************   Valores de norma madeira ******************/

	wxArrayString lista_nome_popular;
	wxArrayString lista_nome_cientifico;
	wxArrayDouble lista_densidade_basica;
	
	size_t index_db;

	double kmod1_norma[5][2] = {	 {0.60,0.30},	//Permanente
									 {0.70,0.45},   //Longa duração
									 {0.80,0.65},	//Média duração
									 {0.90,0.90},   //Curta duração
									 {1.10,1.10} }; //Instantânea

	double kmod2_norma[2][2] = {     {1.00,1.00},	//Classe 1 e 2
									 {0.80,0.9} };  //Classe 3 e 4

	double kmod3_norma[2] = { 1,					//Primeira categoria		
							   0.8 };			    //Segunda categoria

	int kmod_select[4] = {	  0,					//Tipo de Madeira
							  0,					//Classe de carregamento
							  0,					//Classe de umidade
							  0 };					//Categoria da madeira

	double kmod_user[3] = { kmod1_norma[0][0],kmod2_norma[0][0],kmod3_norma[0]};
	bool condicao_mad = false; //0 - seca, 1 - verde

	double gama_w[4] = { 1.4,					//Compressão paralela às fibras
						1.4,					//Flexão
						1.8,					//Tração paralela às fibras (1.4 - NBR7190/2022)
						1.8 };					//Cisalhamento paralelo às fibras 

	//Modelo linear De Paula utilizando a densidade básica Y = A * Db + B
										//C. Angular e Linear
	double coeficientes_verde[5][2] = { {82.7321,-11.8863},		//Tensão de compressão paralela às fibras - CPA
										{165.9581,-21.5093},	//Tensão de ruptura na flexão - MOR
										{15298.55,1876.1964},   //Módulo de elasticidade - MOE
										{21.7172,-6.3744},		//Tensão de compressao perpendicular - CPE
										{15.7886,0}				//Tensão de cisalhamento - CIS
	};	
	double coeficientes_seca[5][2] = {  {110.9629,-5.6659},
										{217.5051,-17.7520},
										{16478.8165,2965.623},
										{28.3314,-7.3117},
										{20.8439,0}
	};


	/*********************************************************/

	wxFont* fonte_resultado;

	//Parametros Seção Transversal
	int tipo_select = 0;
		//Se tipo select = 0 -> Retangulo
		double b=0, h=0;	//Largura x Altura
		double c = 0;		//Espaçamento
		//Se tipo select = 1 - > Circulo
		double raio = 0;

	
	//Método de cálculo
		int met_calc = 0xFF;  //0xFF - NBR 7190/22, 0xFF00 - NBR 7190/97, 0xFF0000 - NBR 7190/82
	//Solicitações
		double momentox = 0, momentoy = 0, normal = 0, cisalhamento = 0;

}INFO;


class CalcParams
{
private:
	CalcParams();
	static CalcParams* instance;
public:
	INFO var;
	static CalcParams* getInstance();
	double get_KMOD()const;
	double get_mat(const int) const;
	~CalcParams();

};


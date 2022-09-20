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
									 {0.70,0.45},   //Longa dura��o
									 {0.80,0.65},	//M�dia dura��o
									 {0.90,0.90},   //Curta dura��o
									 {1.10,1.10} }; //Instant�nea

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

	double gama_w[4] = { 1.4,					//Compress�o paralela �s fibras
						1.4,					//Flex�o
						1.8,					//Tra��o paralela �s fibras (1.4 - NBR7190/2022)
						1.8 };					//Cisalhamento paralelo �s fibras 

	//Modelo linear De Paula utilizando a densidade b�sica Y = A * Db + B
										//C. Angular e Linear
	double coeficientes_verde[5][2] = { {82.7321,-11.8863},		//Tens�o de compress�o paralela �s fibras - CPA
										{165.9581,-21.5093},	//Tens�o de ruptura na flex�o - MOR
										{15298.55,1876.1964},   //M�dulo de elasticidade - MOE
										{21.7172,-6.3744},		//Tens�o de compressao perpendicular - CPE
										{15.7886,0}				//Tens�o de cisalhamento - CIS
	};	
	double coeficientes_seca[5][2] = {  {110.9629,-5.6659},
										{217.5051,-17.7520},
										{16478.8165,2965.623},
										{28.3314,-7.3117},
										{20.8439,0}
	};


	/*********************************************************/

	wxFont* fonte_resultado;

	//Parametros Se��o Transversal
	int tipo_select = 0;
		//Se tipo select = 0 -> Retangulo
		double b=0, h=0;	//Largura x Altura
		double c = 0;		//Espa�amento
		//Se tipo select = 1 - > Circulo
		double raio = 0;

	
	//M�todo de c�lculo
		int met_calc = 0xFF;  //0xFF - NBR 7190/22, 0xFF00 - NBR 7190/97, 0xFF0000 - NBR 7190/82
	//Solicita��es
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


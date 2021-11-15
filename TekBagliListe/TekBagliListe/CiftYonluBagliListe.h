#ifndef CIFTYONLUBAGLILISTE_H
#define CIFTYONLUBAGLILISTE_H
#include "Dugum.h"
class CiftYonluBagliListe {
public:
	CiftYonluBagliListe();//varsayýlan yapýcý;
	~CiftYonluBagliListe();//yýkýca
	void SonaEkle(int);//push_back
	void BasaEkle(int);//push_front
	void SondanSil();//pop_back
	void BastanSil();//pop_front
	int SondakiniGetir();//back
	int BastakiniGetir();//front
	int ElemanSayisiniGetir();//size
	bool BosMu();//empty
	void ListeyiYazdir();
	//void AradanSil(*Dugum);erase
	//void ArayaEkle(Dugum*,int);insert
	//void ListeyiBosalt();clear
private:
	Dugum* basPtr;
	Dugum* sonPtr;



};
#endif
#include "CiftYonluBagliListe.h"
#include <cstdlib>//NULL pointer için
#include <iostream>//cout için
using namespace std;
CiftYonluBagliListe::CiftYonluBagliListe() {//yapýcý
	basPtr = NULL;
	sonPtr = NULL;
}
CiftYonluBagliListe::~CiftYonluBagliListe() {//yýkýcý
	Dugum* geciciPtr;
	while (basPtr!=NULL)
	{
		geciciPtr = basPtr;
		basPtr = basPtr->GetSonrakiPtr();
		delete geciciPtr;
	}
}
void CiftYonluBagliListe::SonaEkle(int v) {
	Dugum* mevcutPtr = new Dugum(v, sonPtr, NULL);
	if (basPtr == NULL)
		basPtr = sonPtr = mevcutPtr;
	else
	{
		sonPtr->SetSonrakiPtr(mevcutPtr);
		sonPtr = mevcutPtr;
	}
}
void CiftYonluBagliListe::BasaEkle(int v) {
	Dugum* mevcutPtr = new Dugum(v, NULL, sonPtr);
	if (basPtr == NULL)
		basPtr = sonPtr = mevcutPtr;
	else
	{

		basPtr->SetOncekiPtr(mevcutPtr);
		basPtr = mevcutPtr;
	}
}
void CiftYonluBagliListe::SondanSil() {
	if (basPtr != NULL) {
		Dugum* geciciPtr = sonPtr;
		if (basPtr == sonPtr) {
			basPtr = sonPtr = NULL;
		}
		else
		{
			sonPtr = sonPtr->GetOncekiPtr();
			sonPtr->SetSonrakiPtr(NULL);
		}
		delete geciciPtr;
	}
	else
		cout << "Listede Silinecek Dugum Yok." << endl;
}
void CiftYonluBagliListe::BastanSil() {
	if (basPtr != NULL) {
		Dugum* geciciPtr = sonPtr;
		if (basPtr == sonPtr) {
			basPtr = sonPtr = NULL;
		}
		else
		{
			basPtr = basPtr->GetSonrakiPtr();
			basPtr->SetOncekiPtr(NULL);
		}
		delete geciciPtr;
	}
	else
		cout << "Silinecek Dugum Yok." << endl;
}
int CiftYonluBagliListe::SondakiniGetir() {
	//LÝSTENÝN BOÞ OLMADIÐI KABULU YAPILMIÞTIR
	//BU FONKSÝYONU ÇAÐIRIRKEN DÝKKATLÝ OL
	return sonPtr->GetVeri();
}
int CiftYonluBagliListe::BastakiniGetir() {
	//LÝSTENÝN BOÞ OLMADIÐI KABULU YAPILMIÞTIR
	//BU FONKSÝYONU ÇAÐIRIRKEN DÝKKATLÝ OL
	return basPtr->GetVeri();
}
int CiftYonluBagliListe::ElemanSayisiniGetir() {
	int sayac = 0;
	Dugum* geciciPtr = basPtr;
	while (geciciPtr != NULL) {
		sayac++;
		geciciPtr = geciciPtr->GetSonrakiPtr();
	}
	return sayac;
}
bool CiftYonluBagliListe::BosMu() {
	return basPtr == NULL;
}
void CiftYonluBagliListe::ListeyiYazdir() {
	Dugum* geciciPtr = basPtr;
	while (geciciPtr!=NULL)
	{
		cout << geciciPtr->GetVeri() << " ";
		geciciPtr = geciciPtr->GetSonrakiPtr();
	}
	cout << endl;
}
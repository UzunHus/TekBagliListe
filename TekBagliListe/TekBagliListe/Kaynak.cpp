#include <iostream>
#include "Dugum.h"
using namespace std;

//liste olu�turma,liste elemanlar�na de�er atama,listeyi ba�tan-sondan yazd�rma,listeden eleman silme,listeyi yok etme.


int main() {
	Dugum* basPtr;//listenin ba��na ptr (head pointer)
	Dugum* sonPtr;//listenin sonuna ptr (last pointer)
	Dugum* mevcutPtr;//Listeye yeni eklenen d���me ptr
	Dugum* geciciPtr;//listeden gezinmek i�in ge�ici pointer
	///B�R�NC� VE SONUNCU D���M� D�NAM�K OLU�TUR///
	basPtr = sonPtr = new Dugum;//varsay�lan yap�y�c�y� �a��r
	basPtr->SetVeri(1);//d���m�n de�eri olarak 1 kullan
	//////////////D���MLER� D�NAM�K OLU�TUR///////////////////
	for (int i = 2;i <= 10;i++) {
		mevcutPtr = new Dugum(i, sonPtr, NULL);//3 parametreli yap�c�
		sonPtr->SetSonrakiPtr(mevcutPtr);
		sonPtr = mevcutPtr;
	}
	//////////L�STEY� BA�TAN SONA GEZ�N////////////
	geciciPtr = basPtr;
	while (geciciPtr != NULL) {
		cout << geciciPtr->GetVeri()<<" ";//Mevcut d���m�n de�erini yazd�r
		geciciPtr = geciciPtr->GetSonrakiPtr();//SONRAK� D���ME Ge�
	}
	cout << endl;
	////////L�STEY� SONDAN BA�A GEZ�N///////
	geciciPtr = sonPtr;
	while (geciciPtr != NULL) {
		cout << geciciPtr->GetVeri() << " ";
		geciciPtr = geciciPtr->GetOncekiPtr();
	}
	cout << endl;
	//listeden 5 say�s�n� silmeye �al��al�m
	Dugum* geciciPtr2;
	geciciPtr = basPtr;
	while (geciciPtr != NULL) {
		if (geciciPtr->GetVeri() == 5) {
			//(geciciPtr->GetOncekiPtr)->SetSonrakiPtr(geciciPtr->GetSonrakiPtr());
			geciciPtr2 = geciciPtr->GetOncekiPtr();
			geciciPtr2->SetSonrakiPtr(geciciPtr->GetSonrakiPtr());

			//geciciPtr = geciciPtr->GetSonrakiPtr();
			//geciciPtr->SetOncekiPtr(geciciPtr2);
			break;
		}
		geciciPtr = geciciPtr->GetSonrakiPtr();
	}
	///L�STEY� TEKRAR YAZDIRALIM/////
	geciciPtr = basPtr;
	while (geciciPtr != NULL) {
		cout << geciciPtr->GetVeri() << " ";//Mevcut d���m�n de�erini yazd�r
		geciciPtr = geciciPtr->GetSonrakiPtr();//SONRAK� D���ME Ge�
	}
	//////D�NAM�K OLU�TURDU�UN D���MLER� YOK ET///////////
	while (basPtr != NULL) {
		geciciPtr = basPtr;
		basPtr = basPtr->GetSonrakiPtr();
		delete geciciPtr;
	}
	return 0;
}
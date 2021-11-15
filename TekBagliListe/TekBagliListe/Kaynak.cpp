#include <iostream>
#include "Dugum.h"
using namespace std;

//liste oluþturma,liste elemanlarýna deðer atama,listeyi baþtan-sondan yazdýrma,listeden eleman silme,listeyi yok etme.


int main() {
	Dugum* basPtr;//listenin baþýna ptr (head pointer)
	Dugum* sonPtr;//listenin sonuna ptr (last pointer)
	Dugum* mevcutPtr;//Listeye yeni eklenen düðüme ptr
	Dugum* geciciPtr;//listeden gezinmek için geçici pointer
	///BÝRÝNCÝ VE SONUNCU DÜÐÜMÜ DÝNAMÝK OLUÞTUR///
	basPtr = sonPtr = new Dugum;//varsayýlan yapýyýcýyý çaðýr
	basPtr->SetVeri(1);//düðümün deðeri olarak 1 kullan
	//////////////DÜÐÜMLERÝ DÝNAMÝK OLUÞTUR///////////////////
	for (int i = 2;i <= 10;i++) {
		mevcutPtr = new Dugum(i, sonPtr, NULL);//3 parametreli yapýcý
		sonPtr->SetSonrakiPtr(mevcutPtr);
		sonPtr = mevcutPtr;
	}
	//////////LÝSTEYÝ BAÞTAN SONA GEZÝN////////////
	geciciPtr = basPtr;
	while (geciciPtr != NULL) {
		cout << geciciPtr->GetVeri()<<" ";//Mevcut düðümün deðerini yazdýr
		geciciPtr = geciciPtr->GetSonrakiPtr();//SONRAKÝ DÜÐÜME Geç
	}
	cout << endl;
	////////LÝSTEYÝ SONDAN BAÞA GEZÝN///////
	geciciPtr = sonPtr;
	while (geciciPtr != NULL) {
		cout << geciciPtr->GetVeri() << " ";
		geciciPtr = geciciPtr->GetOncekiPtr();
	}
	cout << endl;
	//listeden 5 sayýsýný silmeye çalýþalým
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
	///LÝSTEYÝ TEKRAR YAZDIRALIM/////
	geciciPtr = basPtr;
	while (geciciPtr != NULL) {
		cout << geciciPtr->GetVeri() << " ";//Mevcut düðümün deðerini yazdýr
		geciciPtr = geciciPtr->GetSonrakiPtr();//SONRAKÝ DÜÐÜME Geç
	}
	//////DÝNAMÝK OLUÞTURDUÐUN DÜÐÜMLERÝ YOK ET///////////
	while (basPtr != NULL) {
		geciciPtr = basPtr;
		basPtr = basPtr->GetSonrakiPtr();
		delete geciciPtr;
	}
	return 0;
}
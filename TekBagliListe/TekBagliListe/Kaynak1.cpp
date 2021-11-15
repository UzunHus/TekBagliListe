#include "CiftYonluBagliListe.h"
#include <iostream>//cout için
using namespace std;

int main() {
	CiftYonluBagliListe lst;
	if (lst.BosMu())
		cout << "Bu liste su anda bos" << endl;
	lst.SonaEkle(61);
	lst.BasaEkle(45);
	lst.SonaEkle(25);
	lst.SonaEkle(61);
	lst.BasaEkle(12);
	lst.BasaEkle(21);
	lst.ListeyiYazdir();
	cout << "Listedeki eleman sayisi : ";
	cout << lst.ElemanSayisiniGetir() << endl;
	cout << "Listenin ilk elemani  ";
	cout << lst.BastakiniGetir() << " siliniyor" << endl;
	lst.BastanSil();
	cout << "listenin son elemani  ";
	cout << lst.SondakiniGetir() << endl;
	lst.SondanSil();
	lst.ListeyiYazdir();
	cout << "listedeki eleman sayisi : " << lst.ElemanSayisiniGetir() << endl;
	return 0;
}
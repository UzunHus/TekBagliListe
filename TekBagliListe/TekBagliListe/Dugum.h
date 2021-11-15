#ifndef DUGUM_H
#define DUGUM_H
class Dugum {
public:
	Dugum();//vars�yalan yap�c�
	Dugum(int, Dugum*, Dugum*);//3 parametreli yap�c�
	void SetVeri(int);	
	void SetOncekiPtr(Dugum*);
	void SetSonrakiPtr(Dugum*);
		
	int GetVeri();
	Dugum* GetOncekiPtr();
	Dugum* GetSonrakiPtr();
private:
	int veri;//D���m�n saklad��� integer veri
	Dugum* oncekiPtr;//�nceki d���m� i�aret eden pointer
	Dugum* sonrakiPtr;//sonraki d���m� i�aret eden pointer
};
#endif
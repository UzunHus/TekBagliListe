#ifndef DUGUM_H
#define DUGUM_H
class Dugum {
public:
	Dugum();//varsýyalan yapýcý
	Dugum(int, Dugum*, Dugum*);//3 parametreli yapýcý
	void SetVeri(int);	
	void SetOncekiPtr(Dugum*);
	void SetSonrakiPtr(Dugum*);
		
	int GetVeri();
	Dugum* GetOncekiPtr();
	Dugum* GetSonrakiPtr();
private:
	int veri;//Düðümün sakladýðý integer veri
	Dugum* oncekiPtr;//önceki düðümü iþaret eden pointer
	Dugum* sonrakiPtr;//sonraki düðümü iþaret eden pointer
};
#endif
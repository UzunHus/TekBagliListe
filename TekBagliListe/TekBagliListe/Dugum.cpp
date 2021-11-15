#include "Dugum.h"
#include <cstdlib>//null  pointer içn
using namespace std;
Dugum::Dugum() {
	veri = 0;
	oncekiPtr = NULL;
	sonrakiPtr = NULL;
}
Dugum::Dugum(int v, Dugum* oPtr, Dugum* sPtr) {
	veri = v;
	oncekiPtr = oPtr;
	sonrakiPtr = sPtr;
}
void Dugum::SetVeri(int v) {
	veri = v;
}
void Dugum::SetOncekiPtr(Dugum* oPtr) {
	oncekiPtr = oPtr;
}
void Dugum::SetSonrakiPtr(Dugum* sPtr) {
	sonrakiPtr = sPtr;
}
int Dugum::GetVeri() {
	return veri;
}
Dugum* Dugum::GetOncekiPtr() {
	return oncekiPtr;
}
Dugum* Dugum::GetSonrakiPtr() {
	return sonrakiPtr;
}
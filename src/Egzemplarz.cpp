#include "Egzemplarz.h"
Egzemplarz::Egzemplarz(Ksiazka* ksiazka, std::string lokalizacja, int numer) : ksiazka(ksiazka), lokalizacja(lokalizacja), numer(numer) {}
void Egzemplarz::zmienStatus(int status) {}
void Egzemplarz::zarezerwujEgzemplarz(std::string od_date, std::string do_date) {}
Ksiazka* Egzemplarz::getKsiazka() { return ksiazka; }
int Egzemplarz::getStatus() { return status; }
std::string Egzemplarz::getLokalizacja() { return lokalizacja; }
int Egzemplarz::getNumer() { return numer; }
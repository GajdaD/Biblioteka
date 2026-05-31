#include "Ocena.h"
Ocena::Ocena(int ocena, std::string komentarz, Czytelnik* czytelnik, Ksiazka* ksiazka) : ocena(ocena), komentarz(komentarz), czytelnik(czytelnik), ksiazka(ksiazka) {}
void Ocena::edytujOcene(int ocena, std::string komentarz) {}
void Ocena::usunOcene() {}
int Ocena::getOcena() { return ocena; }
std::string Ocena::getKomentarz() { return komentarz; }
Czytelnik* Ocena::getCzytelnik() { return czytelnik; }
Ksiazka* Ocena::getKsiazka() { return ksiazka; }
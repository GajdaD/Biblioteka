#include "Ocena.h"
Ocena::Ocena(int ocena, std::string komentarz, Czytelnik* czytelnik, Ksiazka* ksiazka) : ocena(ocena), komentarz(komentarz), czytelnik(czytelnik), ksiazka(ksiazka) {}
void Ocena::edytujOcene(int nowaOcena, std::string nowyKomentarz) {
    ocena = nowaOcena;
    komentarz = nowyKomentarz;
}
void Ocena::usunOcene() {
    ocena = 0;
    komentarz.clear();
}
int Ocena::getOcena() { return ocena; }
std::string Ocena::getKomentarz() { return komentarz; }
Czytelnik* Ocena::getCzytelnik() { return czytelnik; }
Ksiazka* Ocena::getKsiazka() { return ksiazka; }

#include "Ksiazka.h"
Ksiazka::Ksiazka(std::string tytul, Autor* autor, std::string gatunek) : tytul(tytul), autor(autor), gatunek(gatunek) {}
std::vector<Ocena*> Ksiazka::sprawdzOceny() { return {}; }
void Ksiazka::dodajEgzemplarz(int numer, std::string lokalizacja) {}
void Ksiazka::usunKsiazke() {}
void Ksiazka::recenzujKsiazke(int ocena, std::string komentarz) {}
Egzemplarz* Ksiazka::wolnyEgzemplarz() { return nullptr; }
std::string Ksiazka::getTytul() { return tytul; }
Autor* Ksiazka::getAutor() { return autor; }
std::string Ksiazka::getGatunek() { return gatunek; }
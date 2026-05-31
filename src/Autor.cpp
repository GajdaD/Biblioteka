#include "Autor.h"
Autor::Autor(std::string imie, std::string nazwisko) : imie(imie), nazwisko(nazwisko) {}
void Autor::wyswietlKsiazki() {}
void Autor::dodajKsiazke(std::string tytul, std::string gatunek) {}
std::string Autor::getImie() { return imie; }
std::string Autor::getNazwisko() { return nazwisko; }
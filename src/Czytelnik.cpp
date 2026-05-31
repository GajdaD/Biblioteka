#include "Czytelnik.h"
Czytelnik::Czytelnik(std::string imie, std::string nazwisko, std::string mail) : imie(imie), nazwisko(nazwisko), mail(mail) {}
void Czytelnik::zaplacOplateKarna() {}
void Czytelnik::wyloguj() {}
std::vector<Ksiazka*> Czytelnik::wyszukajKsiazke(std::string fraza) { return {}; }
void Czytelnik::resetujHaslo() {}
double Czytelnik::sprawdzSumeOplat() { return 0.0; }
std::string Czytelnik::getImie() { return imie; }
std::string Czytelnik::getNazwisko() { return nazwisko; }
std::string Czytelnik::getMail() { return mail; }
std::string Czytelnik::getHaslo() { return haslo; }
int Czytelnik::getLimit() { return limit; }
double Czytelnik::getSumaOplatKarnych() { return sumaOplatKarnych; }
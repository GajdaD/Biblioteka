#include "Bibliotekarz.h"
Bibliotekarz::Bibliotekarz(std::string imie, std::string nazwisko, int stanowisko) : imie(imie), nazwisko(nazwisko), stanowisko(stanowisko) {}
void Bibliotekarz::rejestrujCzytelnika(std::string imie, std::string nazwisko, std::string mail, std::string haslo, int limit) {}
void Bibliotekarz::dodajAutora(std::string imie, std::string nazwisko) {}
std::vector<Autor*> Bibliotekarz::wyszukajAutora(std::string imie, std::string nazwisko) { return {}; }
std::string Bibliotekarz::getImie() { return imie; }
std::string Bibliotekarz::getNazwisko() { return nazwisko; }
int Bibliotekarz::getStanowisko() { return stanowisko; }
std::string Bibliotekarz::getHaslo() { return haslo; }
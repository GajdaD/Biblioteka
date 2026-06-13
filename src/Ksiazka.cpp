#include "Ksiazka.h"
#include "Egzemplarz.h"
#include "Ocena.h"
Ksiazka::Ksiazka(std::string tytul, Autor* autor, std::string gatunek) : tytul(tytul), autor(autor), gatunek(gatunek) {}
std::vector<Ocena*> Ksiazka::sprawdzOceny() { return oceny; }
void Ksiazka::dodajEgzemplarz(int numer, std::string lokalizacja) {
    egzemplarze.push_back(new Egzemplarz(this, lokalizacja, numer));
}
void Ksiazka::usunKsiazke() {}
void Ksiazka::recenzujKsiazke(int ocena, std::string komentarz) {
    oceny.push_back(new Ocena(ocena, komentarz, nullptr, this));
}
Egzemplarz* Ksiazka::wolnyEgzemplarz() {
    for (Egzemplarz* egzemplarz : egzemplarze) {
        if (egzemplarz != nullptr && egzemplarz->getStatus() == 1) {
            return egzemplarz;
        }
    }
    return nullptr;
}
std::string Ksiazka::getTytul() { return tytul; }
Autor* Ksiazka::getAutor() { return autor; }
std::string Ksiazka::getGatunek() { return gatunek; }

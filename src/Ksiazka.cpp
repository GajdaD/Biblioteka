#include "Ksiazka.h"
#include "Egzemplarz.h"
#include <iostream>

Ksiazka::Ksiazka(std::string tytul, Autor* autor, std::string gatunek) : tytul(tytul), autor(autor), gatunek(gatunek) {}

std::vector<Ocena*> Ksiazka::sprawdzOceny() { return {}; }

void Ksiazka::dodajEgzemplarz(int numer, std::string lokalizacja) {
    Egzemplarz* e = new Egzemplarz(this, lokalizacja, numer);
    egzemplarze.push_back(e);
    std::cout << "Dodano egzemplarz nr " << numer << " ksiazki '" << tytul << "'." << std::endl;
}

void Ksiazka::usunKsiazke() {}

void Ksiazka::recenzujKsiazke(int ocena, std::string komentarz) {}

Egzemplarz* Ksiazka::wolnyEgzemplarz() {
    for (Egzemplarz* e : egzemplarze) {
        if (e != nullptr && e->getStatus() == 1) {
            return e;
        }
    }
    return nullptr;
}

std::string Ksiazka::getTytul() { return tytul; }
Autor* Ksiazka::getAutor() { return autor; }
std::string Ksiazka::getGatunek() { return gatunek; }

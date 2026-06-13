#include "Czytelnik.h"
#include "Autor.h"
#include "Egzemplarz.h"
#include "Ksiazka.h"
#include "Rezerwacja.h"
#include "Wypozyczenie.h"
#include <algorithm>
#include <cctype>
#include <iostream>

extern std::vector<Ksiazka*> bazaKsiazek;
extern std::vector<Wypozyczenie*> bazaWypozyczen;
std::vector<Rezerwacja*> bazaRezerwacji;

namespace {
std::string maleLitery(std::string tekst) {
    std::transform(tekst.begin(), tekst.end(), tekst.begin(), [](unsigned char znak) {
        return static_cast<char>(std::tolower(znak));
    });
    return tekst;
}

bool zawiera(std::string tekst, std::string fraza) {
    return maleLitery(tekst).find(maleLitery(fraza)) != std::string::npos;
}
}

Czytelnik::Czytelnik(std::string imie, std::string nazwisko, std::string mail)
    : imie(imie), nazwisko(nazwisko), mail(mail), haslo("haslo123"), limit(3), sumaOplatKarnych(0.0) {}

Czytelnik::Czytelnik(std::string imie, std::string nazwisko, std::string mail, std::string haslo, int limit)
    : imie(imie), nazwisko(nazwisko), mail(mail), haslo(haslo), limit(limit), sumaOplatKarnych(0.0) {}

void Czytelnik::zaplacOplateKarna() {
    sumaOplatKarnych = 0.0;
    std::cout << "potwierdzeniePlatnosci(): Oplaty karne zostaly oplacone." << std::endl;
}

void Czytelnik::wyloguj() {
    std::cout << "wyloguj(): Czytelnik " << mail << " zakonczyl sesje." << std::endl;
}

std::vector<Ksiazka*> Czytelnik::wyszukajKsiazke(std::string fraza) {
    std::vector<Ksiazka*> wyniki;
    for (Ksiazka* ksiazka : bazaKsiazek) {
        if (ksiazka == nullptr) {
            continue;
        }

        Autor* autor = ksiazka->getAutor();
        const bool pasujeTytul = zawiera(ksiazka->getTytul(), fraza);
        const bool pasujeGatunek = zawiera(ksiazka->getGatunek(), fraza);
        const bool pasujeAutor = autor != nullptr
            && (zawiera(autor->getImie(), fraza) || zawiera(autor->getNazwisko(), fraza));

        if (pasujeTytul || pasujeGatunek || pasujeAutor) {
            wyniki.push_back(ksiazka);
        }
    }
    return wyniki;
}

std::vector<Ksiazka*> Czytelnik::przegladajDostepneKsiazki() {
    std::vector<Ksiazka*> dostepne;
    for (Ksiazka* ksiazka : bazaKsiazek) {
        if (ksiazka != nullptr && ksiazka->wolnyEgzemplarz() != nullptr) {
            dostepne.push_back(ksiazka);
        }
    }
    return dostepne;
}

Rezerwacja* Czytelnik::zarezerwujEgzemplarz(Egzemplarz* egzemplarz, std::string od_date, std::string do_date) {
    if (egzemplarz == nullptr || egzemplarz->getStatus() != 1 || sprawdzSumeOplat() > 0.0) {
        std::cout << "odmowaRezerwacji(): Brak dostepnego egzemplarza albo istnieja zalegle oplaty." << std::endl;
        return nullptr;
    }

    Rezerwacja* rezerwacja = new Rezerwacja(od_date, do_date, egzemplarz, this, 0);
    rezerwacja->potwierdzRezerwacje();
    bazaRezerwacji.push_back(rezerwacja);
    return rezerwacja;
}

Wypozyczenie* Czytelnik::wypozyczEgzemplarz(Egzemplarz* egzemplarz, std::string od_date, std::string do_date) {
    if (egzemplarz == nullptr || egzemplarz->getStatus() != 1 || sprawdzSumeOplat() > 0.0) {
        std::cout << "odmowaWypozyczenia(): Brak dostepnego egzemplarza albo istnieja zalegle oplaty." << std::endl;
        return nullptr;
    }

    int aktywneWypozyczenia = 0;
    for (Wypozyczenie* wypozyczenie : bazaWypozyczen) {
        if (wypozyczenie != nullptr && wypozyczenie->getCzytelnik() == this && wypozyczenie->getStatus() == 1) {
            aktywneWypozyczenia++;
        }
    }

    if (aktywneWypozyczenia >= limit) {
        std::cout << "odmowaWypozyczenia(): Przekroczono limit wypozyczen." << std::endl;
        return nullptr;
    }

    egzemplarz->zmienStatus(3);
    Wypozyczenie* wypozyczenie = new Wypozyczenie(od_date, do_date, egzemplarz, this, 1);
    bazaWypozyczen.push_back(wypozyczenie);
    std::cout << "potwierdzenieWypozyczenia(): Egzemplarz " << egzemplarz->getNumer() << " zostal wypozyczony." << std::endl;
    return wypozyczenie;
}

void Czytelnik::resetujHaslo() {
    haslo = "haslo123";
    std::cout << "potwierdzenieResetuHasla(): Haslo zostalo zresetowane." << std::endl;
}

double Czytelnik::sprawdzSumeOplat() { return sumaOplatKarnych; }
std::string Czytelnik::getImie() { return imie; }
std::string Czytelnik::getNazwisko() { return nazwisko; }
std::string Czytelnik::getMail() { return mail; }
std::string Czytelnik::getHaslo() { return haslo; }
int Czytelnik::getLimit() { return limit; }
double Czytelnik::getSumaOplatKarnych() { return sumaOplatKarnych; }
void Czytelnik::naliczOplate(double kwota) {
    if (kwota > 0.0) {
        sumaOplatKarnych += kwota;
    }
}

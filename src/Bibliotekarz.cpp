#include "Bibliotekarz.h"
#include "Czytelnik.h"
#include "Autor.h"
#include "Wypozyczenie.h"
#include "Egzemplarz.h"
#include <iostream>

using namespace std;

// Symulacja bazy danych (nie dodajemy tego do .h, zeby byc w 100% zgodnym z diagramem klas)
static vector<string> zajeteMaile;
static vector<Autor*> bazaAutorow;

Bibliotekarz::Bibliotekarz(string imie, string nazwisko, int stanowisko) 
    : imie(imie), nazwisko(nazwisko), stanowisko(stanowisko) {}

// 1.1: sprawdzMail(mail : string) : bool
bool Bibliotekarz::sprawdzMail(string mail) {
    for (string m : zajeteMaile) {
        if (m == mail) return true;
    }
    return false;
}

// 1: rejestrujCzytelnika(...)
void Bibliotekarz::rejestrujCzytelnika(string imie, string nazwisko, string mail, string haslo, int limit) {

    // alt: sprawdzamy warunek za pomoca self-message
    if (!sprawdzMail(mail)) { 
        // [mail nie istnieje w bazie]
        // 1.2: <<create>> Czytelnik(...)
        Czytelnik* nowyCzytelnik = new Czytelnik(imie, nazwisko, mail);
        zajeteMaile.push_back(mail); // Zapis do lokalnej bazy

        // 2: potwierdzenieRejestracji()
        cout << "potwierdzenieRejestracji(): Czytelnik " << mail << " zostal utworzony." << endl;
    } else {
        // [mail istnieje w bazie]
        // 2.2: odmowaRejestracji()
        cout << "odmowaRejestracji(): Podany adres e-mail jest juz zajety!" << endl;
    }
}

void Bibliotekarz::dodajAutora(string imie, string nazwisko) {
    Autor* nowyAutor = new Autor(imie, nazwisko);
    bazaAutorow.push_back(nowyAutor);
}

vector<Autor*> Bibliotekarz::wyszukajAutora(string imie, string nazwisko) {
    vector<Autor*> wyniki;
    for (Autor* a : bazaAutorow) {
        if (a->getImie() == imie && a->getNazwisko() == nazwisko) {
            wyniki.push_back(a);
        }
    }
    return wyniki;
}

string Bibliotekarz::getImie() { return imie; }
string Bibliotekarz::getNazwisko() { return nazwisko; }
int Bibliotekarz::getStanowisko() { return stanowisko; }
string Bibliotekarz::getHaslo() { return haslo; }
// Symulacja globalnej bazy do ktorej Bibliotekarz ma dostep
vector<Wypozyczenie*> bazaWypozyczen; 

// 1: przyjmijKsiazke(numer : int)
void Bibliotekarz::przyjmijKsiazke(int numer) {
    Wypozyczenie* znalezione = nullptr;
    for (auto w : bazaWypozyczen) {
        if (w->getEgzemplarz()->getNumer() == numer) {
            znalezione = w;
            break;
        }
    }

    if (znalezione != nullptr) {
        // 1.1: sprawdzTermin()
        bool terminUplynal = znalezione->sprawdzTermin();

        // Blok opt [termin uplynal]
        if (terminUplynal) {
            // 1.2: wartoscOplaty() - przypisujemy stala kwote dla uproszczenia
            double kwotaKary = 10.0; 
            // 1.3: naliczOplate() do obiektu czytelnika
            znalezione->getCzytelnik()->naliczOplate(kwotaKary);
            cout << "Naliczono oplate karna: " << kwotaKary << " PLN." << endl;
        }

        // 1.4: zmienStatus(status : int) na egzemplarzu
        znalezione->getEgzemplarz()->zmienStatus(1);

        // 1.5: zwrocWypozyczenie()
        znalezione->zwrocWypozyczenie();

        // 1.6: potwierdzenieZwrotu() - wiadomosc zwrotna
        cout << "potwierdzenieZwrotu(): Ksiazka o numerze " << numer << " zostala poprawnie zwrocona." << endl;
    } else {
        cout << "Blad: Brak aktywnego wypozyczenia dla numeru " << numer << endl;
    }
}
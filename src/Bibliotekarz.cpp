#include "Bibliotekarz.h"
#include "Czytelnik.h"
#include "Autor.h"
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
#include "Autor.h"
#include "Ksiazka.h"
#include <iostream>
#include <vector>

using namespace std;

// Zewnetrzna baza ksiazek, do ktorej musimy dodac nowy obiekt, zeby system go "widzial"
extern vector<Ksiazka*> bazaKsiazek;

Autor::Autor(string imie, string nazwisko) : imie(imie), nazwisko(nazwisko) {}

void Autor::dodajKsiazke(string tytul, string gatunek) {
    // Konstruktor <<create>> Ksiazka z wskaźnikiem na aktualnego Autora (this)
    Ksiazka* nowaKsiazka = new Ksiazka(tytul, this, gatunek);
    static int kolejnyNumerEgzemplarza = 1000;
    nowaKsiazka->dodajEgzemplarz(kolejnyNumerEgzemplarza++, "Regal glowny");
    
    // Zapis do naszej symulowanej bazy danych
    bazaKsiazek.push_back(nowaKsiazka);
    
    // Wiadomość powrotna: potwierdzenieDodania()
    cout << "SUKCES: Autor " << nazwisko << " przypisal nowa ksiazke: '" << tytul << "' [" << gatunek << "]" << endl;
}

string Autor::getImie() { return imie; }
string Autor::getNazwisko() { return nazwisko; }
void Autor::wyswietlKsiazki() {}

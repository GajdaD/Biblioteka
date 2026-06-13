#include <iostream>
#include <vector>
#include <string>
#include <limits> // Wymagane do czyszczenia bufora
#include "Bibliotekarz.h"
#include "Czytelnik.h"
#include "Autor.h"
#include "Egzemplarz.h"
#include "Ksiazka.h"
#include "Wypozyczenie.h"

using namespace std;

// Funkcja zabezpieczajaca wczytywanie liczb
int wczytajLiczbe() {
    int liczba;
    while (!(cin >> liczba)) {
        // Jesli uzytkownik wpisze znak zamiast liczby:
        cout << "Blad: Wprowadzono nieprawidlowy znak! Podaj poprawna liczbe: ";
        cin.clear(); // Resetuje stan bledu strumienia
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Czystki bufor az do konca linii (Entera)
    }
    // Wyczyszczenie resztek z bufora (np. jak ktos wpisze "1a")
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return liczba;
}

int main() {
    // Inicjalizacja "sztywnych" danych poczatkowych (Mock database)
    Bibliotekarz admin("Jan", "Kowalski", 1);
    Czytelnik domyslnyCzytelnik("Adam", "Nowak", "adam@mail.com");
    
    int rola = 0;
    
    while (rola != 3) {
        cout << "\n==========================================\n";
        cout << "       SYSTEM BIBLIOTECZNY (V.1.0)        \n";
        cout << "==========================================\n";
        cout << "Wybierz role w systemie (Symulacja logowania):\n";
        cout << "1. Zaloguj jako Bibliotekarz\n";
        cout << "2. Zaloguj jako Czytelnik\n";
        cout << "3. Zakoncz program\n";
        cout << "Wybor: ";
        rola = wczytajLiczbe(); // Uzycie bezpiecznej funkcji!

    if (rola == 1) {
            int opcjaBib = -1;
            while (opcjaBib != 0) {
                cout << "\n--- MENU BIBLIOTEKARZA ---\n";
                cout << "1. Zarejestruj nowego czytelnika\n";
                cout << "2. Zarejestruj nowa ksiazke (wymaga istniejacego autora)\n";
                cout << "3. Dodaj nowego autora do systemu\n";
                cout << "4. Wyszukaj ksiazke\n";
                cout << "5. Przyjmij zwrot ksiazki\n";
                cout << "0. Wyloguj (Powrot do glownego menu)\n";
                cout << "Wybierz akcje: ";
                opcjaBib = wczytajLiczbe();

                if (opcjaBib == 1) {
                    string im, naz, mail;
                    cout << "Podaj imie: "; cin >> im;
                    cout << "Podaj nazwisko: "; cin >> naz;
                    cout << "Podaj e-mail: "; cin >> mail;
                    
                    admin.rejestrujCzytelnika(im, naz, mail, "haslo123", 3);
                } 
                else if (opcjaBib == 2) {
                    // IMPLEMENTACJA ZGODNA Z DIAGRAMEM SEKWENCJI: "rejestracja nowej ksiazki"
                    cout << "\n[Rejestracja Ksiazki] Najpierw musimy znalezc autora.\n";
                    string imA, nazA;
                    cout << "Podaj imie autora: "; cin >> imA;
                    cout << "Podaj nazwisko autora: "; cin >> nazA;
                    
                    // 1: wyszukajAutora(...)
                    vector<Autor*> znalezieniAutorzy = admin.wyszukajAutora(imA, nazA);
                    
                    if (znalezieniAutorzy.empty()) {
                        cout << "Blad: Nie znaleziono takiego autora! Dodaj go najpierw uzywajac opcji nr 3.\n";
                    } else {
                        string tytul, gatunek;
                        cout << "Podaj tytul (bez spacji): "; cin >> tytul;
                        cout << "Podaj gatunek: "; cin >> gatunek;
                        
                        // 2: dodajKsiazke(...) wywolane na znalezionym obiekcie Autora
                        znalezieniAutorzy[0]->dodajKsiazke(tytul, gatunek);
                    }
                }
                else if (opcjaBib == 3) {
                    string imA, nazA;
                    cout << "Podaj imie autora: "; cin >> imA;
                    cout << "Podaj nazwisko autora: "; cin >> nazA;
                    
                    admin.dodajAutora(imA, nazA);
                    cout << "Sukces: Dodano autora do bazy.\n";
                }
                else if (opcjaBib == 4) {
                    string fraza;
                    cout << "Podaj szukana fraze (tytul/nazwisko autora/gatunek): "; 
                    cin >> fraza;
                    
                    vector<Ksiazka*> wyniki = admin.wyszukajKsiazke(fraza);
                    cout << "--- WYNIKI WYSZUKIWANIA ---\n";
                    cout << "Znaleziono " << wyniki.size() << " pozycyj.\n";
                    for(auto k : wyniki) {
                        cout << "- Tytul: " << k->getTytul() 
                             << " | Autor: " << (k->getAutor() != nullptr ? k->getAutor()->getNazwisko() : "brak")
                             << " | Gatunek: " << k->getGatunek() << "\n";
                    }
                }
                else if (opcjaBib == 5) {
                    int numer;
                    cout << "Podaj numer fizycznego egzemplarza do zwrotu: "; 
                    numer = wczytajLiczbe();
                    
                    admin.przyjmijKsiazke(numer);
                }
                else if (opcjaBib != 0) {
                    cout << "Nieznana opcja. Wybierz ponownie.\n";
                }
            }
        }
        else if (rola == 2) {
            int opcjaCzyt = -1;
            while (opcjaCzyt != 0) {
                cout << "\n--- MENU CZYTELNIKA (" << domyslnyCzytelnik.getMail() << ") ---\n";
                cout << "1. Wyszukaj ksiazke\n";
                cout << "2. Przegladaj dostepne ksiazki\n";
                cout << "3. Zarezerwuj pierwszy dostepny egzemplarz\n";
                cout << "4. Wypozycz pierwszy dostepny egzemplarz\n";
                cout << "5. Sprawdz zalegle oplaty\n";
                cout << "6. Zaplac oplaty karne\n";
                cout << "0. Wyloguj (Powrot do glownego menu)\n";
                cout << "Wybierz akcje: ";
                opcjaCzyt = wczytajLiczbe(); // Uzycie bezpiecznej funkcji!

                if (opcjaCzyt == 1) {
                    string fraza;
                    cout << "Podaj szukana fraze (tytul/nazwisko autora/gatunek): ";
                    cin >> fraza;

                    vector<Ksiazka*> wyniki = domyslnyCzytelnik.wyszukajKsiazke(fraza);
                    cout << "--- WYNIKI WYSZUKIWANIA ---\n";
                    cout << "Znaleziono " << wyniki.size() << " pozycyj.\n";
                    for (auto k : wyniki) {
                        cout << "- Tytul: " << k->getTytul()
                             << " | Autor: " << (k->getAutor() != nullptr ? k->getAutor()->getNazwisko() : "brak")
                             << " | Gatunek: " << k->getGatunek() << "\n";
                    }
                } else if (opcjaCzyt == 2) {
                    vector<Ksiazka*> dostepne = domyslnyCzytelnik.przegladajDostepneKsiazki();
                    cout << "--- DOSTEPNE KSIAZKI ---\n";
                    cout << "Znaleziono " << dostepne.size() << " pozycyj.\n";
                    for (auto k : dostepne) {
                        cout << "- Tytul: " << k->getTytul()
                             << " | Wolny egzemplarz nr: " << k->wolnyEgzemplarz()->getNumer() << "\n";
                    }
                } else if (opcjaCzyt == 3 || opcjaCzyt == 4) {
                    string fraza;
                    cout << "Podaj tytul/nazwisko/gatunek ksiazki: ";
                    cin >> fraza;

                    vector<Ksiazka*> wyniki = domyslnyCzytelnik.wyszukajKsiazke(fraza);
                    Ksiazka* wybrana = nullptr;
                    for (auto k : wyniki) {
                        if (k->wolnyEgzemplarz() != nullptr) {
                            wybrana = k;
                            break;
                        }
                    }

                    if (wybrana == nullptr) {
                        cout << "Brak dostepnego egzemplarza dla podanej frazy.\n";
                    } else if (opcjaCzyt == 3) {
                        domyslnyCzytelnik.zarezerwujEgzemplarz(wybrana->wolnyEgzemplarz(), "2026-06-13", "2026-06-20");
                    } else {
                        domyslnyCzytelnik.wypozyczEgzemplarz(wybrana->wolnyEgzemplarz(), "2026-06-13", "2026-07-13");
                    }
                } else if (opcjaCzyt == 5) {
                    cout << "Suma zaleglych oplat: " << domyslnyCzytelnik.sprawdzSumeOplat() << " PLN\n";
                } else if (opcjaCzyt == 6) {
                    domyslnyCzytelnik.zaplacOplateKarna();
                } else if (opcjaCzyt != 0) {
                    cout << "Nieznana opcja. Wybierz ponownie.\n";
                }
            }
        }
        else if (rola != 3) {
            cout << "Nieznana opcja. Wybierz ponownie.\n";
        }
    }

    cout << "\nZamykanie systemu. Milego dnia!\n";
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <limits> // Wymagane do czyszczenia bufora
#include "Bibliotekarz.h"
#include "Czytelnik.h"
#include "Autor.h"
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
                cout << "2. Zarejestruj nowego autora\n";
                cout << "3. Wyszukaj ksiazke\n";
                cout << "4. Przyjmij zwrot ksiazki\n";
                cout << "0. Wyloguj (Powrot do glownego menu)\n";
                cout << "Wybierz akcje: ";
                opcjaBib = wczytajLiczbe(); // Uzycie bezpiecznej funkcji!

                if (opcjaBib == 1) {
                    string im, naz, mail;
                    cout << "Podaj imie: "; cin >> im;
                    cout << "Podaj nazwisko: "; cin >> naz;
                    cout << "Podaj e-mail: "; cin >> mail;
                    
                    admin.rejestrujCzytelnika(im, naz, mail, "haslo123", 3);
                } 
                else if (opcjaBib == 2) {
                    string imA, nazA;
                    cout << "Podaj imie autora: "; cin >> imA;
                    cout << "Podaj nazwisko autora: "; cin >> nazA;
                    
                    admin.dodajAutora(imA, nazA);
                    cout << "Sukces: Dodano autora.\n";
                }
                else if (opcjaBib == 3) {
                    string fraza;
                    cout << "Podaj szukana fraze (tytul/nazwisko autora/gatunek): "; 
                    cin >> fraza;
                    
                    vector<Ksiazka*> wyniki = admin.wyszukajKsiazke(fraza);
                    cout << "--- WYNIKI WYSZUKIWANIA ---\n";
                    cout << "Znaleziono " << wyniki.size() << " pozycyj.\n";
                    for(auto k : wyniki) {
                        cout << "- Tytul: " << k->getTytul() 
                             << " | Autor: " << k->getAutor()->getNazwisko() 
                             << " | Gatunek: " << k->getGatunek() << "\n";
                    }
                }
                else if (opcjaBib == 4) {
                    int numer;
                    cout << "Podaj numer fizycznego egzemplarza do zwrotu: "; 
                    numer = wczytajLiczbe(); // Uzycie bezpiecznej funkcji!
                    
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
                cout << "2. Zarezerwuj egzemplarz\n";
                cout << "3. Wypozycz ksiazke\n";
                cout << "0. Wyloguj (Powrot do glownego menu)\n";
                cout << "Wybierz akcje: ";
                opcjaCzyt = wczytajLiczbe(); // Uzycie bezpiecznej funkcji!

                if (opcjaCzyt >= 1 && opcjaCzyt <= 3) {
                    cout << "\n[INFORMACJA DLA ZESPOLU: Ta sekcja to zadanie dla Osoby nr 2 i 3.]\n";
                    cout << "[Nalezy tutaj podpiac metody klasy Czytelnik po ich implementacji w TDD.]\n";
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
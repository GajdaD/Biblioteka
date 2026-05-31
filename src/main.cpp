#include <iostream>
#include <vector>
#include "Bibliotekarz.h"

using namespace std;

int main() {
    // Inicjalizacja "bazy" - jeden glowny bibliotekarz
    Bibliotekarz admin("Jan", "Kowalski", 1);
    
    cout << "==========================================\n";
    cout << "       SYSTEM BIBLIOTECZNY                \n";
    cout << "==========================================\n";

    int opcja = 0;
    while (opcja != 3) {
        cout << "\n--- MENU BIBLIOTEKARZA ---\n";
        cout << "1. Zarejestruj nowego czytelnika\n";
        cout << "2. Zarejestruj nowego autora\n";
        cout << "3. Zakoncz program\n";
        cout << "Wybierz akcje: ";
        cin >> opcja;

        if (opcja == 1) {
            string im, naz, mail;
            cout << "Podaj imie: "; cin >> im;
            cout << "Podaj nazwisko: "; cin >> naz;
            cout << "Podaj e-mail: "; cin >> mail;
            
            // Limit sztywno ustawiony na 3 (zgodnie z ukladem)
            admin.rejestrujCzytelnika(im, naz, mail, "domyslneHaslo", 3);
            
        } else if (opcja == 2) {
            string imie_autora, nazwisko_autora;
            cout << "Podaj imie autora: "; cin >> imie_autora;
            cout << "Podaj nazwisko autora: "; cin >> nazwisko_autora;
            
            admin.dodajAutora(imie_autora, nazwisko_autora);
            cout << "Dodano autora do systemu.\n";
            
        } else if (opcja != 3) {
            cout << "Nieznana opcja. Sprobuj ponownie.\n";
        }
    }

    cout << "\nZamykanie systemu. Milego dnia!\n";
    return 0;
}
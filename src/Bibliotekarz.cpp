// Bibliotekarz.cpp
#include "Bibliotekarz.h"
#include "Czytelnik.h"
#include <iostream>

void Bibliotekarz::rejestrujCzytelnika(std::string imie, std::string nazwisko, std::string mail, std::string haslo, int limit) {
    // Symulacja sprawdzenia w bazie, czy dany adres e-mail już istnieje
    bool czyIstniejeWBazie = false; 

    if (!czyIstniejeWBazie) { // Blok [czytelnik nie istnieje]
        // <<create>> Wywołanie konstruktora z diagramu klas
        Czytelnik nowyCzytelnik(imie, nazwisko, mail); 
        
        // Symulacja wiadomości powrotnej: potwierdzenieRejestracji()
        std::cout << "Zarejestrowano nowego czytelnika: " << mail << std::endl;
    } else { // Blok [czytelnik juz istnieje]
        // Symulacja wiadomości powrotnej: odmowaRejestracji()
        std::cout << "Odmowa: Czytelnik z tym adresem e-mail juz istnieje!" << std::endl;
    }
}
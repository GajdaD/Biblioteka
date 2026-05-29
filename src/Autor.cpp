// Autor.cpp
#include "Autor.h"
#include "Ksiazka.h"
#include <iostream>

void Autor::dodajKsiazke(std::string tytul, std::string gatunek) {
    // <<create>> Wywołanie konstruktora Ksiazki zgodnie z poprawionym diagramem klas.
    // Przekazujemy aktualny obiekt Autora używając wyłuskania *this
    Ksiazka nowaKsiazka(tytul, *this, gatunek);

    // Symulacja wiadomości powrotnej: potwierdzenieDodania()
    std::cout << "Potwierdzenie: Dodano ksiazke '" << tytul << "' do bazy." << std::endl;
}
// Czytelnik.cpp
#include "Czytelnik.h"
#include "Ksiazka.h"
#include <vector>
#include <string>

// UWAGA: W prawdziwym kodzie bazaKsiazek musialaby byc przekazana jako argument
// lub byc globalnym Singletonem systemu, aby Czytelnik mial co przeszukiwac.
std::vector<Ksiazka> Czytelnik::wyszukajKsiazke(std::string fraza, const std::vector<Ksiazka>& bazaKsiazek) {
    std::vector<Ksiazka> wynikiWyszukiwania;

    // Realizacja petli [loop: dopóki nie wybrano tytulu] z diagramu sekwencji
    for (Ksiazka ksiazka : bazaKsiazek) {
        // Blok [alt] z diagramu - zamiana nieistniejących metod na poprawne gettery
        if (ksiazka.getTytul() == fraza || 
            ksiazka.getGatunek() == fraza || 
            ksiazka.getAutor().getNazwisko() == fraza) {
            
            wynikiWyszukiwania.push_back(ksiazka);
        }
    }

    return wynikiWyszukiwania;
}
#include <gtest/gtest.h>
#include "../src/Bibliotekarz.h"
#include "../src/Ksiazka.h"
#include "../src/Autor.h"

using namespace std;

// Deklarujemy, ze gdzies istnieje taka globalna baza, do ktorej dorzucimy testowe dane
extern vector<Ksiazka*> bazaKsiazek; 

TEST(WyszukiwanieTest, ZnajdowaniePoTytuleIAutorze) {
    // Czyszczenie bazy (dobra praktyka w testach)
    bazaKsiazek.clear();

    // Przygotowanie testowych danych
    Autor autor1("J.R.R.", "Tolkien");
    Ksiazka k1("Hobbit", &autor1, "Fantasy");
    bazaKsiazek.push_back(&k1);

    Bibliotekarz admin("Jan", "Kowalski", 1);

    // Dzialanie 1: Szukamy po tytule
    vector<Ksiazka*> wynikiTytul = admin.wyszukajKsiazke("Hobbit");
    ASSERT_EQ(wynikiTytul.size(), 1); // Musi znalezc 1 ksiazke
    EXPECT_EQ(wynikiTytul[0]->getTytul(), "Hobbit");

    // Dzialanie 2: Szukamy po nazwisku autora
    vector<Ksiazka*> wynikiAutor = admin.wyszukajKsiazke("Tolkien");
    ASSERT_EQ(wynikiAutor.size(), 1);
    EXPECT_EQ(wynikiAutor[0]->getAutor()->getNazwisko(), "Tolkien");
}

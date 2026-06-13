#include <gtest/gtest.h>
#include "../src/Czytelnik.h"
#include "../src/Egzemplarz.h"
#include "../src/Ksiazka.h"
#include "../src/Autor.h"

using namespace std;

TEST(ZwrotTest, NaliczanieOplatyKarnej) {
    Czytelnik czytelnik("Jan", "Kowalski", "jan@mail.com");

    // Zgodnie z diagramem: 1.3: naliczOplate()
    czytelnik.naliczOplate(15.50);

    EXPECT_EQ(czytelnik.getSumaOplatKarnych(), 15.50);
}

TEST(ZwrotTest, ZmianaStatusuEgzemplarzaPrzyZwrocie) {
    Autor autor("Adam", "Mickiewicz");
    Ksiazka ksiazka("Dziady", &autor, "Dramat");
    Egzemplarz egzemplarz(&ksiazka, "Regal 1", 123);

    // Zgodnie z diagramem: 1.4: zmienStatus(status : int)
    egzemplarz.zmienStatus(1); // Zakladamy, ze '1' oznacza 'dostepny na polce'

    EXPECT_EQ(egzemplarz.getStatus(), 1);
}

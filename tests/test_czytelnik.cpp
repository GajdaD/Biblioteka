#include <gtest/gtest.h>
#include "../src/Autor.h"
#include "../src/Czytelnik.h"
#include "../src/Egzemplarz.h"
#include "../src/Ksiazka.h"
#include "../src/Ocena.h"
#include "../src/Rezerwacja.h"
#include "../src/Wypozyczenie.h"

#include <vector>

using namespace std;

extern vector<Ksiazka*> bazaKsiazek;
extern vector<Wypozyczenie*> bazaWypozyczen;
extern vector<Rezerwacja*> bazaRezerwacji;

class CzytelnikTest : public ::testing::Test {
protected:
    void SetUp() override {
        bazaKsiazek.clear();
        bazaWypozyczen.clear();
        bazaRezerwacji.clear();
    }
};

TEST_F(CzytelnikTest, KonstruktorZUstawieniamiZapamietujeHasloILimit) {
    Czytelnik czytelnik("Anna", "Nowak", "anna@mail.com", "tajne", 5);

    EXPECT_EQ(czytelnik.getHaslo(), "tajne");
    EXPECT_EQ(czytelnik.getLimit(), 5);
    EXPECT_EQ(czytelnik.getSumaOplatKarnych(), 0.0);
}

TEST_F(CzytelnikTest, WyszukujeKsiazkePoTytuleAutorzeIGatunku) {
    Autor autor("Olga", "Tokarczuk");
    Ksiazka ksiazka("Bieguni", &autor, "Powiesc");
    bazaKsiazek.push_back(&ksiazka);

    Czytelnik czytelnik("Jan", "Kowalski", "jan@mail.com");

    EXPECT_EQ(czytelnik.wyszukajKsiazke("bie").size(), 1);
    EXPECT_EQ(czytelnik.wyszukajKsiazke("Tokarczuk").size(), 1);
    EXPECT_EQ(czytelnik.wyszukajKsiazke("pow").size(), 1);
    EXPECT_TRUE(czytelnik.wyszukajKsiazke("brak").empty());
}

TEST_F(CzytelnikTest, PrzegladaTylkoKsiazkiZWolnymEgzemplarzem) {
    Autor autor("Adam", "Mickiewicz");
    Ksiazka dostepna("Pan Tadeusz", &autor, "Epopeja");
    Ksiazka niedostepna("Dziady", &autor, "Dramat");
    dostepna.dodajEgzemplarz(10, "Regal 1");
    niedostepna.dodajEgzemplarz(20, "Regal 2");
    niedostepna.wolnyEgzemplarz()->zmienStatus(3);
    bazaKsiazek.push_back(&dostepna);
    bazaKsiazek.push_back(&niedostepna);

    Czytelnik czytelnik("Jan", "Kowalski", "jan@mail.com");
    vector<Ksiazka*> wyniki = czytelnik.przegladajDostepneKsiazki();

    ASSERT_EQ(wyniki.size(), 1);
    EXPECT_EQ(wyniki[0]->getTytul(), "Pan Tadeusz");
}

TEST_F(CzytelnikTest, RezerwacjaZmieniaStatusEgzemplarza) {
    Autor autor("Stanislaw", "Lem");
    Ksiazka ksiazka("Solaris", &autor, "Science fiction");
    ksiazka.dodajEgzemplarz(101, "Regal SF");
    Czytelnik czytelnik("Jan", "Kowalski", "jan@mail.com");

    Rezerwacja* rezerwacja = czytelnik.zarezerwujEgzemplarz(ksiazka.wolnyEgzemplarz(), "2026-06-13", "2026-06-20");

    ASSERT_NE(rezerwacja, nullptr);
    EXPECT_EQ(rezerwacja->getStatus(), 1);
    EXPECT_EQ(rezerwacja->getEgzemplarz()->getStatus(), 2);
    EXPECT_EQ(bazaRezerwacji.size(), 1);
}

TEST_F(CzytelnikTest, RezerwacjaJestOdrzuconaPrzyZaleglychOplatach) {
    Autor autor("Stanislaw", "Lem");
    Ksiazka ksiazka("Solaris", &autor, "Science fiction");
    ksiazka.dodajEgzemplarz(101, "Regal SF");
    Czytelnik czytelnik("Jan", "Kowalski", "jan@mail.com");
    czytelnik.naliczOplate(12.0);

    Rezerwacja* rezerwacja = czytelnik.zarezerwujEgzemplarz(ksiazka.wolnyEgzemplarz(), "2026-06-13", "2026-06-20");

    EXPECT_EQ(rezerwacja, nullptr);
    EXPECT_EQ(ksiazka.wolnyEgzemplarz()->getStatus(), 1);
    EXPECT_TRUE(bazaRezerwacji.empty());
}

TEST_F(CzytelnikTest, WypozyczenieZmieniaStatusIDodajeWpisDoBazy) {
    Autor autor("J.R.R.", "Tolkien");
    Ksiazka ksiazka("Hobbit", &autor, "Fantasy");
    ksiazka.dodajEgzemplarz(301, "Regal F");
    Czytelnik czytelnik("Jan", "Kowalski", "jan@mail.com");

    Wypozyczenie* wypozyczenie = czytelnik.wypozyczEgzemplarz(ksiazka.wolnyEgzemplarz(), "2026-06-13", "2026-07-13");

    ASSERT_NE(wypozyczenie, nullptr);
    EXPECT_EQ(wypozyczenie->getStatus(), 1);
    EXPECT_EQ(wypozyczenie->getEgzemplarz()->getStatus(), 3);
    EXPECT_EQ(bazaWypozyczen.size(), 1);
}

TEST_F(CzytelnikTest, WypozyczeniePilnujeLimituCzytelnika) {
    Autor autor("J.R.R.", "Tolkien");
    Czytelnik czytelnik("Jan", "Kowalski", "jan@mail.com", "haslo", 1);
    Ksiazka pierwsza("Hobbit", &autor, "Fantasy");
    Ksiazka druga("Silmarillion", &autor, "Fantasy");
    pierwsza.dodajEgzemplarz(301, "Regal F");
    druga.dodajEgzemplarz(302, "Regal F");

    Wypozyczenie* pierwsze = czytelnik.wypozyczEgzemplarz(pierwsza.wolnyEgzemplarz(), "2026-06-13", "2026-07-13");
    Wypozyczenie* drugie = czytelnik.wypozyczEgzemplarz(druga.wolnyEgzemplarz(), "2026-06-13", "2026-07-13");

    ASSERT_NE(pierwsze, nullptr);
    EXPECT_EQ(drugie, nullptr);
    EXPECT_EQ(bazaWypozyczen.size(), 1);
    EXPECT_EQ(druga.wolnyEgzemplarz()->getStatus(), 1);
}

TEST_F(CzytelnikTest, ZaplataCzysciOplatyKarne) {
    Czytelnik czytelnik("Jan", "Kowalski", "jan@mail.com");
    czytelnik.naliczOplate(20.0);

    czytelnik.zaplacOplateKarna();

    EXPECT_EQ(czytelnik.sprawdzSumeOplat(), 0.0);
}

TEST(KsiazkaTest, DodajeEgzemplarzeIOceny) {
    Autor autor("Adam", "Mickiewicz");
    Ksiazka ksiazka("Dziady", &autor, "Dramat");

    ksiazka.dodajEgzemplarz(123, "Regal 1");
    ksiazka.recenzujKsiazke(5, "Bardzo dobra");

    ASSERT_NE(ksiazka.wolnyEgzemplarz(), nullptr);
    EXPECT_EQ(ksiazka.wolnyEgzemplarz()->getNumer(), 123);
    ASSERT_EQ(ksiazka.sprawdzOceny().size(), 1);
    EXPECT_EQ(ksiazka.sprawdzOceny()[0]->getOcena(), 5);
}

TEST(RezerwacjaTest, UsuniecieRezerwacjiPrzywracaDostepnoscEgzemplarza) {
    Autor autor("Stanislaw", "Lem");
    Ksiazka ksiazka("Solaris", &autor, "Science fiction");
    Egzemplarz egzemplarz(&ksiazka, "Regal SF", 101);
    Czytelnik czytelnik("Jan", "Kowalski", "jan@mail.com");
    Rezerwacja rezerwacja("2026-06-13", "2026-06-20", &egzemplarz, &czytelnik, 0);

    rezerwacja.potwierdzRezerwacje();
    rezerwacja.usunRezerwacje();

    EXPECT_EQ(rezerwacja.getStatus(), 0);
    EXPECT_EQ(egzemplarz.getStatus(), 1);
}

TEST(WypozyczenieTest, ZwrotPrzywracaDostepnoscEgzemplarza) {
    Autor autor("J.R.R.", "Tolkien");
    Ksiazka ksiazka("Hobbit", &autor, "Fantasy");
    Egzemplarz egzemplarz(&ksiazka, "Regal F", 301);
    Czytelnik czytelnik("Jan", "Kowalski", "jan@mail.com");
    Wypozyczenie wypozyczenie("2026-06-13", "2026-07-13", &egzemplarz, &czytelnik, 1);
    egzemplarz.zmienStatus(3);

    wypozyczenie.zwrocWypozyczenie();

    EXPECT_EQ(wypozyczenie.getStatus(), 0);
    EXPECT_EQ(egzemplarz.getStatus(), 1);
}

TEST(OcenaTest, EdycjaIUsuniecieZmieniajaDaneOceny) {
    Ocena ocena(3, "Ok", nullptr, nullptr);

    ocena.edytujOcene(5, "Bardzo dobra");
    EXPECT_EQ(ocena.getOcena(), 5);
    EXPECT_EQ(ocena.getKomentarz(), "Bardzo dobra");

    ocena.usunOcene();
    EXPECT_EQ(ocena.getOcena(), 0);
    EXPECT_TRUE(ocena.getKomentarz().empty());
}

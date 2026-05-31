#include <gtest/gtest.h>
#include "../src/Bibliotekarz.h"
#include "../src/Autor.h"

using namespace std;

TEST(BibliotekarzTest, DodawanieIWyszukiwanieAutora) {
    Bibliotekarz admin("Anna", "Nowak", 1);
    admin.dodajAutora("Stanislaw", "Lem");

    vector<Autor*> wyniki = admin.wyszukajAutora("Stanislaw", "Lem");

    ASSERT_EQ(wyniki.size(), 1);
    EXPECT_EQ(wyniki[0]->getNazwisko(), "Lem");
}

TEST(BibliotekarzTest, TestGetterow) {
    Bibliotekarz admin("Anna", "Nowak", 1);
    EXPECT_EQ(admin.getImie(), "Anna");
    EXPECT_EQ(admin.getStanowisko(), 1);
}
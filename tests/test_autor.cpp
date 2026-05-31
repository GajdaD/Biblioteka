#include <gtest/gtest.h>
#include "../src/Autor.h"

TEST(AutorTest, TworzenieAutora) {
    Autor autor("Adam", "Mickiewicz");
    EXPECT_EQ(autor.getImie(), "Adam");
    EXPECT_EQ(autor.getNazwisko(), "Mickiewicz");
}
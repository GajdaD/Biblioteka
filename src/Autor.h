#ifndef AUTOR_H
#define AUTOR_H
#include <string>
#include <vector>

class Ksiazka; // Forward declaration

class Autor {
private:
    std::string imie;
    std::string nazwisko;
public:
    Autor(std::string imie, std::string nazwisko);
    void wyswietlKsiazki();
    void dodajKsiazke(std::string tytul, std::string gatunek);
    std::string getImie();
    std::string getNazwisko();
};
#endif

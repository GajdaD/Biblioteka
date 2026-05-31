#ifndef CZYTELNIK_H
#define CZYTELNIK_H
#include <string>
#include <vector>

class Ksiazka;

class Czytelnik {
private:
    std::string imie;
    std::string nazwisko;
    std::string mail;
    std::string haslo;
    int limit;
    double sumaOplatKarnych;
public:
    Czytelnik(std::string imie, std::string nazwisko, std::string mail);
    void zaplacOplateKarna();
    void wyloguj();
    std::vector<Ksiazka*> wyszukajKsiazke(std::string fraza);
    void resetujHaslo();
    double sprawdzSumeOplat();
    std::string getImie();
    std::string getNazwisko();
    std::string getMail();
    std::string getHaslo();
    int getLimit();
    double getSumaOplatKarnych();
};
#endif
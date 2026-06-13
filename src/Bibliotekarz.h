#ifndef BIBLIOTEKARZ_H
#define BIBLIOTEKARZ_H
#include <string>
#include <vector>

class Autor;
class Ksiazka;

class Bibliotekarz {
private:
    std::string imie;
    std::string nazwisko;
    int stanowisko;
    std::string haslo;
    bool sprawdzMail(std::string mail); 

public:
    Bibliotekarz(std::string imie, std::string nazwisko, int stanowisko);
    void rejestrujCzytelnika(std::string imie, std::string nazwisko, std::string mail, std::string haslo, int limit);
    void dodajAutora(std::string imie, std::string nazwisko);
    std::vector<Autor*> wyszukajAutora(std::string imie, std::string nazwisko);
    std::string getImie();
    std::string getNazwisko();
    int getStanowisko();
    std::string getHaslo();
    void przyjmijKsiazke(int numer);
    std::vector<Ksiazka*> wyszukajKsiazke(std::string fraza);
};
#endif

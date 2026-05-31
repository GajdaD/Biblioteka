#ifndef KSIAZKA_H
#define KSIAZKA_H
#include <string>
#include <vector>

class Autor;
class Ocena;
class Egzemplarz;

class Ksiazka {
private:
    std::string tytul;
    Autor* autor;
    std::string gatunek;
public:
    Ksiazka(std::string tytul, Autor* autor, std::string gatunek);
    std::vector<Ocena*> sprawdzOceny();
    void dodajEgzemplarz(int numer, std::string lokalizacja);
    void usunKsiazke();
    void recenzujKsiazke(int ocena, std::string komentarz);
    Egzemplarz* wolnyEgzemplarz();
    std::string getTytul();
    Autor* getAutor();
    std::string getGatunek();
};
#endif
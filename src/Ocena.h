#ifndef OCENA_H
#define OCENA_H
#include <string>

class Czytelnik;
class Ksiazka;

class Ocena {
private:
    int ocena;
    std::string komentarz;
    Czytelnik* czytelnik;
    Ksiazka* ksiazka;
public:
    Ocena(int ocena, std::string komentarz, Czytelnik* czytelnik, Ksiazka* ksiazka);
    void edytujOcene(int ocena, std::string komentarz);
    void usunOcene();
    int getOcena();
    std::string getKomentarz();
    Czytelnik* getCzytelnik();
    Ksiazka* getKsiazka();
};
#endif
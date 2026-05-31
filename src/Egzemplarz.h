#ifndef EGZEMPLARZ_H
#define EGZEMPLARZ_H
#include <string>

class Ksiazka;

class Egzemplarz {
private:
    Ksiazka* ksiazka;
    int status;
    std::string lokalizacja;
    int numer;
public:
    Egzemplarz(Ksiazka* ksiazka, std::string lokalizacja, int numer);
    void zmienStatus(int status);
    void zarezerwujEgzemplarz(std::string od_date, std::string do_date);
    Ksiazka* getKsiazka();
    int getStatus();
    std::string getLokalizacja();
    int getNumer();
};
#endif
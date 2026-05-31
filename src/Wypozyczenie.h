#ifndef WYPOZYCZENIE_H
#define WYPOZYCZENIE_H
#include <string>

class Egzemplarz;
class Czytelnik;

class Wypozyczenie {
private:
    std::string od_date;
    std::string do_date;
    Egzemplarz* egzemplarz;
    Czytelnik* czytelnik;
    int status;
public:
    Wypozyczenie(std::string od_date, std::string do_date, Egzemplarz* egzemplarz, Czytelnik* czytelnik, int status);
    void zwrocWypozyczenie();
    std::string getOd();
    std::string getDo();
    Egzemplarz* getEgzemplarz();
    Czytelnik* getCzytelnik();
    int getStatus();
};
#endif
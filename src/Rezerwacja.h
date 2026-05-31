#ifndef REZERWACJA_H
#define REZERWACJA_H
#include <string>

class Egzemplarz;
class Czytelnik;

class Rezerwacja {
private:
    std::string od_date;
    std::string do_date;
    Egzemplarz* egzemplarz;
    Czytelnik* czytelnik;
    int status;
public:
    Rezerwacja(std::string od_date, std::string do_date, Egzemplarz* egzemplarz, Czytelnik* czytelnik, int status);
    void potwierdzRezerwacje();
    void usunRezerwacje();
    std::string getOd();
    std::string getDo();
    Egzemplarz* getEgzemplarz();
    Czytelnik* getCzytelnik();
    int getStatus();
};
#endif
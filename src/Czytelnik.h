#ifndef CZYTELNIK_H
#define CZYTELNIK_H
#include <string>
#include <vector>

class Ksiazka;
class Egzemplarz;
class Rezerwacja;
class Wypozyczenie;

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
    Czytelnik(std::string imie, std::string nazwisko, std::string mail, std::string haslo, int limit);
    void zaplacOplateKarna();
    void wyloguj();
    std::vector<Ksiazka*> wyszukajKsiazke(std::string fraza);
    std::vector<Ksiazka*> przegladajDostepneKsiazki();
    Rezerwacja* zarezerwujEgzemplarz(Egzemplarz* egzemplarz, std::string od_date, std::string do_date);
    Wypozyczenie* wypozyczEgzemplarz(Egzemplarz* egzemplarz, std::string od_date, std::string do_date);
    void resetujHaslo();
    double sprawdzSumeOplat();
    std::string getImie();
    std::string getNazwisko();
    std::string getMail();
    std::string getHaslo();
    int getLimit();
    double getSumaOplatKarnych();
    void naliczOplate(double kwota);
};
#endif

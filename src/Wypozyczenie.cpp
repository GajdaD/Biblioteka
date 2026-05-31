#include "Wypozyczenie.h"
Wypozyczenie::Wypozyczenie(std::string od_date, std::string do_date, Egzemplarz* egzemplarz, Czytelnik* czytelnik, int status) : od_date(od_date), do_date(do_date), egzemplarz(egzemplarz), czytelnik(czytelnik), status(status) {}
void Wypozyczenie::zwrocWypozyczenie() {}
std::string Wypozyczenie::getOd() { return od_date; }
std::string Wypozyczenie::getDo() { return do_date; }
Egzemplarz* Wypozyczenie::getEgzemplarz() { return egzemplarz; }
Czytelnik* Wypozyczenie::getCzytelnik() { return czytelnik; }
int Wypozyczenie::getStatus() { return status; }
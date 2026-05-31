#include "Wypozyczenie.h"
Wypozyczenie::Wypozyczenie(std::string od_date, std::string do_date, Egzemplarz* egzemplarz, Czytelnik* czytelnik, int status) : od_date(od_date), do_date(do_date), egzemplarz(egzemplarz), czytelnik(czytelnik), status(status) {}
void Wypozyczenie::zwrocWypozyczenie() {
    status = 0; // 0 oznacza archiwalne/zwrocone
}
std::string Wypozyczenie::getOd() { return od_date; }
std::string Wypozyczenie::getDo() { return do_date; }
Egzemplarz* Wypozyczenie::getEgzemplarz() { return egzemplarz; }
Czytelnik* Wypozyczenie::getCzytelnik() { return czytelnik; }
int Wypozyczenie::getStatus() { return status; }
bool Wypozyczenie::sprawdzTermin() {
    // Uproszczenie na potrzeby braku bazy SQL i zarzadzania czasem w C++
    // Zakladamy na sztywno, ze termin minal, by wywolac blok [opt] z opcja kary
    return true; 
}
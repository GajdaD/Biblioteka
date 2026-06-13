#include "Rezerwacja.h"
#include "Egzemplarz.h"
Rezerwacja::Rezerwacja(std::string od_date, std::string do_date, Egzemplarz* egzemplarz, Czytelnik* czytelnik, int status) : od_date(od_date), do_date(do_date), egzemplarz(egzemplarz), czytelnik(czytelnik), status(status) {}
void Rezerwacja::potwierdzRezerwacje() {
    status = 1;
    if (egzemplarz != nullptr) {
        egzemplarz->zmienStatus(2);
    }
}
void Rezerwacja::usunRezerwacje() {
    status = 0;
    if (egzemplarz != nullptr) {
        egzemplarz->zmienStatus(1);
    }
}
std::string Rezerwacja::getOd() { return od_date; }
std::string Rezerwacja::getDo() { return do_date; }
Egzemplarz* Rezerwacja::getEgzemplarz() { return egzemplarz; }
Czytelnik* Rezerwacja::getCzytelnik() { return czytelnik; }
int Rezerwacja::getStatus() { return status; }

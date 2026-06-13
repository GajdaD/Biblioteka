# System Biblioteki

Konsolowy system zarządzania biblioteką napisany w **C++17**. Projekt realizuje wzorzec obiektowy zgodny z diagramami UML i obsługuje dwie role użytkowników: Bibliotekarza i Czytelnika.

---

## Funkcjonalności

### Bibliotekarz
- Rejestracja nowego czytelnika (z walidacją unikalności e-mail)
- Dodawanie autorów i książek do bazy
- Wyszukiwanie książek po tytule, nazwisku autora lub gatunku
- Przyjmowanie zwrotu egzemplarza (z automatycznym naliczaniem opłat karnych za przekroczenie terminu)
- Dodawanie fizycznych egzemplarzy do istniejących książek

### Czytelnik
- Wyszukiwanie i przeglądanie dostępnych książek
- Rezerwacja egzemplarza (z datą od/do)
- Wypożyczanie egzemplarza
- Sprawdzanie i opłacanie zaległych opłat karnych

---

## Struktura projektu

```
Biblioteka/
├── src/
│   ├── main.cpp           # Punkt wejścia, menu konsolowe
│   ├── Bibliotekarz.cpp/h # Logika bibliotekarza, globalna baza danych
│   ├── Czytelnik.cpp/h    # Logika czytelnika
│   ├── Ksiazka.cpp/h      # Model książki
│   ├── Autor.cpp/h        # Model autora
│   ├── Egzemplarz.cpp/h   # Fizyczny egzemplarz książki (status, lokalizacja)
│   ├── Rezerwacja.cpp/h   # Rezerwacja egzemplarza
│   ├── Wypozyczenie.cpp/h # Wypożyczenie z kontrolą terminu
│   └── Ocena.cpp/h        # Ocena i recenzja książki
├── tests/
│   ├── test_autor.cpp
│   ├── test_bibliotekarz.cpp
│   ├── test_zwrot.cpp
│   └── test_wyszukiwanie.cpp
├── CMakeLists.txt
└── README.md
```

---

## Wymagania

- **C++17** lub nowszy
- **CMake** >= 3.14
- **GCC** (lub inny kompilator zgodny z C++17)
- Połączenie z internetem przy pierwszym buildzie (CMake pobiera GoogleTest automatycznie)

---

## Budowanie i uruchomienie

```bash
# Sklonuj repozytorium
git clone https://github.com/GajdaD/Biblioteka.git
cd Biblioteka

# Utwórz katalog build i skonfiguruj
cmake -B build

# Zbuduj projekt
cmake --build build

# Uruchom aplikację
./build/BibliotekaApp
```

---

## Testy jednostkowe

Testy są realizowane przy użyciu **GoogleTest 1.14.0**, pobieranego automatycznie przez CMake.

```bash
# Uruchom wszystkie testy
cd build && ctest --output-on-failure

# Lub bezpośrednio
./build/BibliotekaTests
```

### Zakres testów (6 testów w 4 plikach)

| Plik | Test | Opis |
|------|------|------|
| `test_autor.cpp` | `TworzenieAutora` | Konstruktor i gettery klasy Autor |
| `test_bibliotekarz.cpp` | `DodawanieIWyszukiwanieAutora` | Dodawanie i wyszukiwanie autora przez bibliotekarza |
| `test_bibliotekarz.cpp` | `TestGetterow` | Gettery klasy Bibliotekarz |
| `test_zwrot.cpp` | `NaliczanieOplatyKarnej` | Naliczanie opłaty karnej na czytelniku |
| `test_zwrot.cpp` | `ZmianaStatusuEgzemplarzaPrzyZwrocie` | Zmiana statusu egzemplarza przy zwrocie |
| `test_wyszukiwanie.cpp` | `ZnajdowaniePoTytuleIAutorze` | Wyszukiwanie książki po tytule i autorze |

---

## Architektura

Projekt oparty jest na programowaniu obiektowym. Każda klasa odpowiada encji z diagramu klas UML:

| Klasa | Odpowiedzialność |
|-------|-----------------|
| `Bibliotekarz` | Zarządzanie systemem, globalny dostęp do baz danych |
| `Czytelnik` | Operacje czytelnika, śledzenie opłat karnych |
| `Ksiazka` | Model książki, lista egzemplarzy |
| `Egzemplarz` | Fizyczny egzemplarz z numerem, lokalizacją i statusem |
| `Autor` | Dane autora, lista powiązanych książek |
| `Rezerwacja` | Rezerwacja egzemplarza z datami i statusem |
| `Wypozyczenie` | Wypożyczenie z kontrolą terminu (`sprawdzTermin()`) |
| `Ocena` | Recenzja i ocena książki przez czytelnika |

Komentarze w kodzie są ściśle powiązane z krokami diagramów sekwencji UML (np. `// 1.1: sprawdzMail(...)`, `// 1.4: zmienStatus(status)`), co ułatwia śledzenie zgodności implementacji z projektem.

---

## Baza danych (symulacja)

System używa globalnych wektorów jako uproszczonej bazy danych (in-memory):

```cpp
static vector<string> zajeteMaile;     // Zajęte adresy e-mail
static vector<Autor*> bazaAutorow;     // Baza autorów
vector<Ksiazka*> bazaKsiazek;          // Baza książek (extern – dostępna w testach)
vector<Wypozyczenie*> bazaWypozyczen;  // Aktywne wypożyczenia
```

---

## Repozytorium

- **22 commity** na gałęzi `main`
- Klasy Czytelnik i Rezerwacja rozwijane były na osobnej gałęzi `feature/czytelnik-rezerwacja-wypozyczenie` i włączone do `main` przez **Pull Request #1**

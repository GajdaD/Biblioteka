cmake_minimum_required(VERSION 3.14)
cmake_policy(SET CMP0135 NEW)
project(Biblioteka)

# Ustawienie standardu C++
set(CMAKE_CXX_STANDARD 17)

# Automatyczne pobranie GoogleTest (wymagane do TDD)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

# Cel 1: Główna aplikacja
add_executable(BibliotekaApp 
    src/main.cpp 
    src/Autor.cpp 
    src/Ksiazka.cpp 
    src/Czytelnik.cpp 
    src/Bibliotekarz.cpp 
    src/Egzemplarz.cpp 
    src/Ocena.cpp 
    src/Rezerwacja.cpp 
    src/Wypozyczenie.cpp
)

# Cel 2: Testy jednostkowe
enable_testing()
add_executable(BibliotekaTests 
    tests/test_autor.cpp
    tests/test_bibliotekarz.cpp
    src/Autor.cpp
    src/Ksiazka.cpp
    src/Czytelnik.cpp
    src/Bibliotekarz.cpp
    src/Egzemplarz.cpp
    src/Ocena.cpp
    src/Rezerwacja.cpp
    src/Wypozyczenie.cpp
)
# Linkowanie biblioteki testowej
target_link_libraries(BibliotekaTests gtest_main)

# Rejestracja testów w CMake
include(GoogleTest)
gtest_discover_tests(BibliotekaTests)
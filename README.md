# Algorytmy i Struktury Danych (AiSD) 2026

Repozytorium zawiera zbiór zadań, projektów i implementacji algorytmów realizowanych w ramach laboratoriów z przedmiotu **Algorytmy i Struktury Danych (AiSD)**. Wszystkie kody zostały napisane w języku C++ (standard C++20).

## 📂 Struktura repozytorium

Projekty zostały podzielone na katalogi odpowiadające poszczególnym laboratoriom oraz tematyce zajęć:

### Laby 01 - Podstawy języka C++
* **Zadanie_1**: Podstawowe operacje wejścia/wyjścia oraz pętle. Program wypisujący powitanie w pętli z instrukcjami warunkowymi.
* **Zadanie_2**: Klasyczny problem *FizzBuzz* zrealizowany dla liczb od 0 do 99.
* **Zadanie_3**: Generowanie ciągów arytmetycznych. Program oblicza i formatuje wyrazy ciągu z podziałem na kolumny.

### Laby 02 - Praca na tablicach i wektorach
* **Zadanie_22**: Funkcje pomocnicze do obsługi kontenerów. Wypełnianie wektora (`std::vector`) liczbami losowymi z wykorzystaniem generatora `std::mt19937` i rozkładu jednostajnego oraz ich wypisywanie.
* **Zadanie_23**: Odwracanie kolejności elementów w tablicy (wektorze) w miejscu, z wykorzystaniem funkcji `std::swap`.

### Laby 04 - Złożoność obliczeniowa
* **Zadanie43 (Sprawdzanie rozłączności tablic)**: Rozbudowany projekt porównujący wydajność 5 różnych algorytmów sprawdzających, czy dwie tablice są rozłączne.
  * Zaimplementowano algorytmy od metody "brute-force" o złożoności $O(N \cdot M)$, aż po zoptymalizowane podejścia wykorzystujące sortowanie i przeszukiwanie binarne o złożoności $O(N \log N)$.
  * Projekt wykonuje automatyczne pomiary czasu działania w mikrosekundach i eksportuje wyniki do pliku `dane.csv`. 
  * Szczegółowy opis problemu znajduje się w osobnym pliku [README.md wewnątrz katalogu Zadanie43](./Laby_04/Zadanie43/README.md).

### Sortowania - Algorytmy sortowania i rekurencja
* **InsertionSort**: Implementacja algorytmu *Sortowania przez wstawianie* (Insertion Sort). Zawiera również porównanie różnych, mniej optymalnych wersji tego algorytmu.
* **MergeSort**: *do zrobienia*.

## 🛠️ Wymagania i uruchomienie

Całe repozytorium jest skonfigurowane jako rozwiązanie programu Visual Studio.

1. Sklonuj repozytorium na swój dysk.
2. Otwórz plik rozwiązania: `aisd.sln` w programie **Microsoft Visual Studio** (zalecana wersja z obsługą C++20).
3. W *Eksploratorze rozwiązań* wybierz projekt, który chcesz uruchomić, i wybierz **Ustaw jako projekt startowy**.

## ⚙️ Technologie
* Język: **C++** (Standard: `stdcpp20`)
* Środowisko: **Visual Studio 2022**
* System kompilacji: **MSBuild**

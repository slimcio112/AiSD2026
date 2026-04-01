# Zadanie 4.3 - Sprawdzanie rozłączności tablic
Dane są dwie tablice liczb o rozmiarach $m$ oraz $n$. Problem polega na sprawdzeniu, czy tablice są rozłączne.

Do rozwiązania problemu zaproponowano następujące algorytmy:
* **a)** Wyszukać w tablicy większej elementy tablicy mniejszej.
* **b)** Wyszukać w tablicy mniejszej elementy tablicy większej.
* **c)** Posortować większą tablicę, a następnie wyszukać w niej elementy tablicy mniejszej.
* **d)** Posortować mniejszą tablicę, a następnie wyszukać w niej elementy tablicy większej.
* **e)** Posortować obie tablice, a następnie porównywać najmniejsze elementy każdej z tablic, odrzucić mniejszy jeżeli są różne; powtarzać do wyczerpania elementów (podejście przypominające fazę scalania w algorytmie *Merge Sort*).

Zadanie polegało na określeniu złożoności obliczeniowej każdego z podejść oraz empirycznym porównaniu ich wydajności.

---

Na podstawie analizy algorytmów (zakładając, że $N$ to rozmiar większej tablicy, a $M$ mniejszej), prezentuje się ona następująco:

* **Algorytm A:** $O(N \cdot M)$ – Rozwiązanie najwolniejsze (brute-force).
* **Algorytm B:** $O(N \cdot M)$ – Również rozwiązanie najwolniejsze (odwrotny brute-force).
* **Algorytm C:** $O(N \log N + M \log N) = O(N \log N)$ – Czas działania porównywalny z algorytm E.
* **Algorytm D:** $O(M \log M + N \log M) = O(N \log M)$ – Teoretycznie najszybsze rozwiązanie wszędzie tam, gdzie rozmiary tablic znacząco się różnią ($n \neq m$).
* **Algorytm E:** $O(N \log N + M \log M + N + M) = O(N \log N)$ – Czas działania porównywalny z algorytmem C.

---

* `Zadanie43.cpp` – Główny plik z implementacją wszystkich 5 wariantów algorytmów (`sola`, `solb`, `solc`, `sold`, `sole`) oraz pętlą wykonującą testy wydajnościowe dla rosnących wielkości $n$ i $m$.
* `utils.h` oraz `utils.cpp` – Zestaw narzędzi pomocniczych, zawierający funkcje do:
    * Wypełniania wektorów liczbami losowymi o rozkładzie jednostajnym (`fill_random`).
    * Wypisywania tablic (`print`).
    * Precyzyjnego pomiaru czasu wykonania w mikrosekundach (`get_time`, `measure_us`).
* `dane.csv` – Plik wynikowy (generowany przy każdym uruchomieniu programu) zawierający czasy wykonania każdego z algorytmów oraz informację o tym, który z nich okazał się najszybszy w danej iteracji.

---

Poniżej znajduje się wykres punktowy wygenerowany w excelu dla $n \in [0,10000]$ i $m\in[0,10000]$ przedstawiający, który algorytm był najszybszy dla danego n,m.
<img width="1997" height="1403" alt="image" src="https://github.com/user-attachments/assets/680dfac5-a7ae-40f9-ae1c-2cdeaf805772" />

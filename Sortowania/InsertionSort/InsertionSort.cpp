#include <iostream>
#include <vector>

void InsertionSort(std::vector<int>& arr) {
    // iterujemy od drugiego do ostatniego elementu tablicy
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i]; // Ustawiamy klucz na pierwszy element po prawej od posortowanej podtablicy
        int j = i - 1; // Ustawiamy wskaznik j na element znajdujacy sie bezposrednio po lewej od key

        // Przepychamy elementy wieksze od key o jeden na prawo az do momentu gdy nie bedzie juz elementow wiekszych
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Kopiujemy elementy w prawo
            j--; // Idziemy w lewo
        }
        arr[j+1] = key; // wstawiamy klucz w miejsce gdzie byl ostatni przesuniety element
    }
}

// Pętla for zamiast While
/*
void InsertionSort(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j;

        for (j = i - 1; j >= 0 && arr[j] > key; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}
*/

// Wersja mniej optymalna
void InsertionSortSwap(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            int tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
        }
    }
}

int main()
{
    std::vector<int> arr{ 1,5,32,3,4,1,2,6,2 };
    for (auto& e : arr) {
        std::cout << e << " ";
    }
    std::cout << "\n";

    InsertionSort(arr);
    for (auto& e : arr) {
        std::cout << e << " ";
    }
}

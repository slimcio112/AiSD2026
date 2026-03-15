#include <iostream>
#include <random>
#include <vector>

// Funkcja wyświetlająca elementy tablicy
template <typename kontener>
void print(const kontener& k) {
    for (const auto& e : k) {
        std::cout << e << " ";
    }
    std::cout << "\n";
}

// Funkcja wypełniająca tablice losowymi wartościami z przedziału od m do M
void fill_random(std::vector<int>& arr, int m, int M) {
    std::random_device rd; // generowanie ziarna losowości
    std::mt19937 gen(rd()); // generator liczb losowych
    std::uniform_int_distribution<int> dist(m, M); // rozkład jednostajny

    for (int& e : arr) {
        e = dist(gen);
    }
}

int main()
{
    std::vector<int> moja_tablica(50);
    fill_random(moja_tablica, 100, 300);

    print(moja_tablica);
}


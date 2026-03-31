#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>
#include "utils.h"

/*
A: O(N*M) Najwolniejsze
B: O(N*M) Najwolniejsze
C: O(N log N + M log N) = O(N log N) porownywalne z E
D: O(M log M + N log M) = O(N log M) powinno byc najszybsze wszedzie poza n=m
E: O(N log N + M log M + N + M) = O(N log N) porownywalne z C
*/

bool sola(std::vector<int>& wieksza, std::vector<int>& mniejsza) {
    
    for (const auto& e1 : mniejsza) {
        for (const auto& e2 : wieksza) {
            if (e1 == e2) return false;
        }
    }
    return true;
}

bool solb(std::vector<int>& wieksza, std::vector<int>& mniejsza) {

    for (const auto& e1 : wieksza) {
        for (const auto& e2 : mniejsza) {
            if (e2 == e1) return false;
        }
    }
    return true;
}

bool solc(std::vector<int>& wieksza, std::vector<int>& mniejsza) {

    std::sort(wieksza.begin(), wieksza.end());

    for (const auto& e : mniejsza) {
        if(std::binary_search(wieksza.begin(), wieksza.end(), e)) return false;
    }
    return true;
}

bool sold(std::vector<int>& wieksza, std::vector<int>& mniejsza) {

    std::sort(mniejsza.begin(), mniejsza.end());

    for (const auto& e : wieksza) {
        if (std::binary_search(mniejsza.begin(), mniejsza.end(), e)) return false;
    }
    return true;
}

bool sole(std::vector<int>& wieksza, std::vector<int>& mniejsza) {

    std::sort(mniejsza.begin(), mniejsza.end());
    std::sort(wieksza.begin(), wieksza.end());

    auto Nmin = wieksza.begin();
    auto Mmin = mniejsza.begin();

    while (Nmin != wieksza.end() && Mmin != mniejsza.end()) {

        if (*Nmin == *Mmin) {
            return false;
        }
        else if (*Nmin < *Mmin) {
            Nmin++;
        }
        else {
            Mmin++;
        }

    }
    return true;
}

int main()
{
    std::ofstream file("dane.csv");
    file << "n;m;czas_A;czas_B;czas_C;czas_D;czas_E;najszybszy\n";

    int max_size = 10000;
    int krok = 50;

    for (int n = krok; n <= max_size; n += krok) {
        for (int m = krok; m <= max_size; m += krok) {

            int rozmiar_wiekszej = std::max(n, m);
            int rozmiar_mniejszej = std::min(n, m);

            std::vector<int> A(rozmiar_wiekszej);
            std::vector<int> B(rozmiar_mniejszej);

            fill_random(A, 1, 100000);
            fill_random(B, 200000, 300000);

            volatile bool res;
            double czas_a, czas_b, czas_c, czas_d, czas_e;

            // Algorytm A
            std::vector<int> Ac = A; std::vector<int> Bc = B;
            auto start = get_time();
            res = sola(Ac, Bc);
            czas_a = measure_us(start);

            // Algorytm B
            Ac = A; Bc = B;
            start = get_time();
            res = solb(Ac, Bc);
            czas_b = measure_us(start);

            // Algorytm C
            Ac = A; Bc = B;
            start = get_time();
            res = solc(Ac, Bc);
            czas_c = measure_us(start);

            // Algorytm D
            Ac = A; Bc = B;
            start = get_time();
            res = sold(Ac, Bc);
            czas_d = measure_us(start);

            // Algorytm E
            Ac = A; Bc = B;
            start = get_time();
            res = sole(Ac, Bc);
            czas_e = measure_us(start);

            double min_time = czas_a;
            std::string winner = "A";

            if (czas_b < min_time) { min_time = czas_b; winner = "B"; }
            if (czas_c < min_time) { min_time = czas_c; winner = "C"; }
            if (czas_d < min_time) { min_time = czas_d; winner = "D"; }
            if (czas_e < min_time) { min_time = czas_e; winner = "E"; }

            // Zapis do CSV
            file << n << ";" << m << ";"
                << (long long)czas_a << ";" << (long long)czas_b << ";" << (long long)czas_c << ";"
                << (long long)czas_d << ";" << (long long)czas_e << ";"
                << winner << "\n";
        }
    }
    file.close();
    return 0;
}
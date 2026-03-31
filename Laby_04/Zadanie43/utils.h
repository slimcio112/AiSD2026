#pragma once

#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include <string>

// Funkcja wyświetlająca elementy tablicy
template <typename kontener>
void print(const kontener& k) {
    for (const auto& e : k) {
        std::cout << e << " ";
    }
    std::cout << "\n";
}

// Funkcja wypełniająca tablice losowymi elementami z rozkładem jednostajnym
template <typename kontener>
void fill_random(kontener& arr, int m, int M) {
    std::random_device rd; // generowanie ziarna losowości
    std::mt19937 gen(rd()); // generator liczb losowych
    std::uniform_int_distribution<int> dist(m, M); // rozkład jednostajny

    for (int& e : arr) {
        e = dist(gen);
    }
}

using time_point = std::chrono::steady_clock::time_point; // alias na typ czasu

time_point get_time(); // pobieranie momentu w czasie

double measure_us(time_point start); // ile czasu minelo od start


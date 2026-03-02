#include <iostream>
#include <iomanip>

int ilosc_wyrazow{ 100 };

int ciag(int a_1, int r, int n) {
    int an{};

    an = a_1 + (n - 1) * r;

    return an;
}

int main()
{
    int a_1{ 5 };
    int r{ 3 };
    int kolumny{ 20 };

    for (std::size_t i{1}; i <= ilosc_wyrazow; i++) {
        std::cout << std::setw(4) << ciag(a_1, r, i);
        if (i % kolumny == 0) std::cout << '\n';
    }
}


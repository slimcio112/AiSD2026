#include <iostream>
#include <vector>
#include <utility>
#include <iterator>

// odwracamy tablice korzystajac z swap z biblioteki utility
template <typename kontener>
void odwroc(kontener& k) {

    size_t n = std::size(k);

    for (size_t i = 0; i < n / 2; i++) {
        std::swap(k[i], k[n - i - 1]);
    }
}

// Funkcja wyświetlająca elementy tablicy
template <typename kontener>
void print(const kontener& k) {
    for (const auto& e : k) {
        std::cout << e << " ";
    }
    std::cout << "\n";
}

int main()
{
    std::vector<int> mojaTablica{ 0,1,2,3,4,5,6,7,8,9,10 };
    odwroc(mojaTablica);
    print(mojaTablica);
}

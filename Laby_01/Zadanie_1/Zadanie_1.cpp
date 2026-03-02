#include <iostream>

int main()
{
    int REP{ 104 };

    for (std::size_t i = 0; i < REP; i++) {
        std::cout << "Hello World AiSD!\n";
        if (i % 5 == 0) std::cout << "To juz " << i << " razy. Duzo jeszcze?\n";
        if (i == 100) {
            std::cout << "Mam dosc, sam sobie wyswietlaj...\n";
            break;
        }
    }
}
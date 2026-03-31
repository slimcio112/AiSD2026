#include "utils.h"
#include <fstream>

// pobieranie aktualnego momentu w czasie
time_point get_time() {
    return std::chrono::steady_clock::now();
}

// ile czasu mineło (mikro sekundy)
double measure_us(time_point start) {
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    return elapsed.count();
}

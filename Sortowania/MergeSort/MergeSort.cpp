#include <iostream>

int silnia_rec(int n) {
    if (n == 1) return 1;
    else return n * silnia_rec(n - 1);
}

int silnia_iter(int n) {
    int x = 1;

    for (int i = 1; i <= n; i++) {
        x = x * i;
    }
    return x;
}

int fib(int n) {
    if (n < 2) return n;
    else return (fib(n - 2) + fib(n - 1));
}

int main()
{
    std::cout << fib(13);
}

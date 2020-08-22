#include <iostream>
#include <cassert>


int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

long long int fibonacci_fast(int n) {
    long long int a[n+1];
    a[0]=1;
    a[1]=1;
    for(int i=2;i<=n;i++)
        a[i]=a[i-1]+a[i-2];
    // write your code here

    return a[n];
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    std::cin >> n;

    //std::cout << fibonacci_naive(n) << '\n';
    //test_solution();
    std::cout << fibonacci_fast(n) << '\n';
//    std::getchar();
    return 0;
}

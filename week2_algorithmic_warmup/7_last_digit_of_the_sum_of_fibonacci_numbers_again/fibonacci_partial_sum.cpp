#include <iostream>
#include <vector>
#include<cmath>
using std::vector;

int fibonacci_sum(long long n, long long m) {
    if (n <= 1)
        return n;

    vector<long long int> a;
    a.push_back(0);
    a.push_back(1);
    long long int x,t;
    long long i=2;
    while(1){
        x=(a[i-1]+a[i-2])%m;
        a.push_back(x);
        if(a[i]==1&&a[i-1]==0){
            t=a.size()-2;
            break;
        }
        i++;
    }
    return a[n%t]%m;
}

int main() {
    long long m,n;
    std::cin >> m >> n;
    long long sum = std::abs(fibonacci_sum(n+2,10)-fibonacci_sum(m+1,10)+10);
    std::cout << sum%10 << '\n';
}

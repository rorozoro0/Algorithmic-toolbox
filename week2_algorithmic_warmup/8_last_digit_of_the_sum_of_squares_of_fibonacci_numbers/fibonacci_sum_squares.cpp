#include<vector>
#include <iostream>
using namespace std;

long long get_fibonacci_huge(long long n, long long m) {
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
    long long n = 0;
    cin >> n;
    cout << (get_fibonacci_huge(n,10)*get_fibonacci_huge(n+1,10))%10;
}

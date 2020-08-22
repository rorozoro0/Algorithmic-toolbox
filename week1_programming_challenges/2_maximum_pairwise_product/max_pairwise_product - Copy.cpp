#include <iostream>
#include <vector>
#include <algorithm>

long long int MaxPairwiseProduct(const std::vector<long long int>& numbers) {
    long long max_product = 0;
    long long n = numbers.size();
    long long m1=-1,m2=-1;
    for(long long int i=0;i<n;i++)
    {
        if(m1==-1||numbers[m1]<numbers[i])
            m1=i;
    }
    for(long long int i=0;i<n;i++)
    {
        if((i!=m1)&&(m2==-1||numbers[m2]<numbers[i]))
            m2=i;
    }
    max_product=numbers[m1]*numbers[m2];

    return max_product;
}

int main() {
    long long int n;
    std::cin>>n;
    std::vector<long long int> numbers(n);
    for (long long int i = 0; i < n; ++i) {
        std::cin>>numbers[i];
    }

    std::cout<<MaxPairwiseProduct(numbers)<< "\n";
    return 0;
}

#include <iostream>
#include <vector>
#include<cmath>
#include<algorithm>

using namespace std;

vector<int> optimal_summands(long long int n) {
  vector<int> summands;
  long long int k = floor((-1+sqrtl(1+8*n))/2)-1;

  int sum = k*(k+1)/2;


  for(int i=1;i<=k;i++)
  {
      summands.push_back(i);
  }

    summands.push_back(n-sum);
  return summands;
}

int main() {
  long long int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}

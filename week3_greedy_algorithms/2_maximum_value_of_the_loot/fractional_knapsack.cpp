#include <iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
struct knap
{
    double values;
    double weights;
    double rate;
};
bool compare_rate(knap k1 ,knap k2)
{
    return (k1.rate<k2.rate);
}

double get_optimal_value(int capacity, knap k[],int n) {
  double value = 0.0;
  for(int i=n-1;i>=0;i--)
  {
      if(capacity>=k[i].weights){
        capacity-=k[i].weights;
        value+=k[i].values;
      }
      else{
        value+=capacity * k[i].rate;
        break;
      }
  }

  // write your code here

  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  knap k[n];
  for (int i = 0; i < n; i++) {
    cin >> k[i].values >> k[i].weights;
    k[i].rate=k[i].values/k[i].weights;
  }

    sort(k,k+n,compare_rate);
  double optimal_value = get_optimal_value(capacity,k,n);


  cout << setprecision(10)<<fixed<<optimal_value <<endl;
  return 0;
}

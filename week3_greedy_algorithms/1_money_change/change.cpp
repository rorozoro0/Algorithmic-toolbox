#include <iostream>
using namespace std;
int get_change(int m) {
  //write your code here
  int n = m/10;
  m=m%10;
  n=n+m/5;
  m=m%5;
  n=n+m;
  return n;
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}

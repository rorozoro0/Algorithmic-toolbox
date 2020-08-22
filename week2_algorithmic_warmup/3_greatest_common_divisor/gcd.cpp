#include <iostream>

int gcd(int a, int b) {
  if(b==0)
    return a;
  int c = a%b;
  return gcd(b,c);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd(a,b) << std::endl;
  return 0;
}

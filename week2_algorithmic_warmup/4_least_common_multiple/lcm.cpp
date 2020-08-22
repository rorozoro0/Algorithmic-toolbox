#include <iostream>

int gcd(int a, int b) {
  if(b==0)
    return a;
  int c = a%b;
  return gcd(b,c);
}

long long lcm(int a, int b) {
  int d=gcd(a,b);

  return (long long) a * b/d;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}

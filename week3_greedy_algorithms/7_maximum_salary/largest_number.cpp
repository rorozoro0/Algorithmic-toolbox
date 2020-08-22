#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
int Comp(string a, string b)
{
    string ab = a.append(b);
    string ba = b.append(a);

    // Now see which of the two formed numbers is greater
    return ab.compare(ba) > 0 ? 1: 0;
}

void largest_number(vector<string> a) {
  //write your code here
  sort(a.begin(),a.end(),Comp);
  for (size_t i = 0; i < a.size(); i++) {
    std::cout<< a[i];
  }

}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  largest_number(a);
}

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
struct Term {
  int minSteps;
  int prevTerm;
};
vector<struct Term> Terms;
struct Term DP_primitive_calculator(int n) {

  if (n == 1) {
    return {0, -1};
  }
  if (n < Terms.size()) {
    return Terms[n];
  }
  struct Term answer = { DP_primitive_calculator(n-1).minSteps+1, n-1 };
  if (n %2 == 0 && DP_primitive_calculator(n/2).minSteps+1 < answer.minSteps) {
    answer = { DP_primitive_calculator(n/2).minSteps+1, n/2 };
  }
  if (n %3 == 0 && DP_primitive_calculator(n/3).minSteps+1 < answer.minSteps) {
    answer = { DP_primitive_calculator(n/3).minSteps+1, n/3 };
  }
  Terms[n] = answer;
  return answer;
}

int printSolution(int n) {
  int prev = DP_primitive_calculator(n).prevTerm;
  if (prev != -1) {
    printSolution(prev);
  }
  std::cout << n << " ";
}

int main() {
  int n;
  std::cin >> n;
  struct Term Answer = DP_primitive_calculator(n);
  std::cout << Answer.minSteps << std::endl;
  printSolution(n);
  std::cout << std::endl;
}

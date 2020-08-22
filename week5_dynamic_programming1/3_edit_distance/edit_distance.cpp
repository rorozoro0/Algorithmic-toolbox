#include <iostream>
#include <string>
#include<algorithm>

using std::string;

int edit_distance(string &str1,string &str2, int m, int n) {
  // Create a table to store results of subproblems
    int dp[m + 1][n + 1];

    // Fill d[][] in bottom up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;

            else if (j == 0)
                dp[i][j] = i;

            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            else
                dp[i][j] = 1 + std::min(std::min(dp[i][j - 1],
                                   dp[i - 1][j]),
                                   dp[i - 1][j - 1]);
        }
    }

    return dp[m][n];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2,str1.length(), str2.length()) << std::endl;
  return 0;
}

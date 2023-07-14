#include <bits/stdc++.h> 
using namespace std;

int getMaxPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int maxi = -1e8;

    // base case
    for (int j = 0; j < m; j++) {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = matrix[i][j] + dp[i - 1][j];
            int ld = 0; // Declare ld with default value
            int rd = 0; // Declare rd with default value

            if (j > 0) {
                ld = matrix[i][j] + dp[i - 1][j - 1];
            }

            if (j < m - 1) {
                rd = matrix[i][j] + dp[i - 1][j + 1];
            }

            dp[i][j] = max(u, max(ld, rd));
        }
    }

    for (int j = 0; j < m; j++) {
        maxi = max(maxi, dp[n - 1][j]);
    }

    return maxi;
}

int main() {
    vector<vector<int>> matrix{{1, 2, 10, 4},
                               {100, 3, 2, 1},
                               {1, 1, 20, 2},
                               {1, 2, 2, 1}};

    cout << getMaxPathSum(matrix) << endl;

    return 0;
}

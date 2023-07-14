#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    // Base cases
    if (i < 0 || j < 0) {
        return INT_MAX;
    }
    if (i == 0 && j == 0) {
        return grid[0][0];
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    
    // Calculate the minimum path sum by considering the up and left paths
    int up = grid[i][j] + solve(i - 1, j, grid, dp);
    int left = grid[i][j] + solve(i, j - 1, grid, dp);

    return dp[i][j] = min(up, left);
}

int minSumPath(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n - 1, m - 1, grid, dp);
}


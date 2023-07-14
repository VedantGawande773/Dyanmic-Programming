#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int solve(int ind, vector<int>& heights, vector<int>& dp) {
    // Base case
    if (ind == 0)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int right = INT_MAX; //if we are at the stating position so right is not availble hence max value

    int left = solve(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
    if (ind >= 2)
        right = solve(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);

    dp[ind] = min(left, right);
    return dp[ind];
}

int frogJump(int n, vector<int>& heights) {
    vector<int> dp(n+1, -1);
    int result = solve(n - 1, heights, dp);
    return result;
}

int main() {
    // Test case 1
    vector<int> heights1 = {7, 5, 5, 8, 4, 9, 1, 1, 10};
    int result1 = frogJump(heights1.size(), heights1);
    cout << "Minimum cost: " << result1 << endl;

    // Test case 2
    vector<int> heights2 = {8, 7, 1, 3, 9, 2};
    int result2 = frogJump(heights2.size(), heights2);
    cout << "Minimum cost: " << result2 << endl;

    // Test case 3
    vector<int> heights3 = {7, 4, 4, 2, 6, 6, 3, 4};
    int result3 = frogJump(heights3.size(), heights3);
    cout << "Minimum cost: " << result3 << endl;

    // Test case 4
    vector<int> heights4 = {4, 8, 3, 10, 4, 4};
    int result4 = frogJump(heights4.size(), heights4);
    cout << "Minimum cost: " << result4 << endl;

    return 0;
}

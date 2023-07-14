/*By using the tabulation approach, the code iteratively calculates the minimum cost from the first index to the last index. Each element in the dp array represents the minimum cost to reach that index. Finally, the dp[n-1] value is the minimum cost to reach the last index, which is printed as the output.*/

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    for (int i = 1; i < n; ++i)
    {
        int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        dp[i] = min(left, right);
    }

    return dp[n - 1];
}

int main()
{
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

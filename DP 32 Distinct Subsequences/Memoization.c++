#include<bits/stdc++.h>
using namespace std;

    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        // Base cases
        if (j < 0) return 1;
        if (i < 0) return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j]) {
            int leave = solve(i - 1, j - 1, s1, s2, dp);
            int stay = solve(i - 1, j, s1, s2, dp);
            return dp[i][j] = leave + stay;
        } else {
            return dp[i][j] = solve(i - 1, j, s1, s2, dp);
        }
    }

	int distinctSubsequences(string &s, string &t)
	{
		
			int n = s.size();
			int m = t.size();
			vector<vector<int>> dp(n, vector<int>(m, -1));
			return solve(n - 1, m - 1, s, t, dp);

	}

    int main() {

    string s1 = "babgbag";
    string s2 = "bag";

    cout << "The Count of Distinct Subsequences is "
    <<distinctSubsequences(s1,s2);
    }
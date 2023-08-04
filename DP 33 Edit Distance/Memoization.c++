    #include<bits/stdc++.h>
    using namespace std;

    int solve(int ind1, int ind2, string &str1, string &str2,vector<vector<int>> &dp) {
        // Base case
        if (ind1 < 0) return ind2 + 1;
        if (ind2 < 0) return ind1 + 1;

        if(dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (str1[ind1] == str2[ind2])
            dp[ind1][ind2] =  solve(ind1 - 1, ind2 - 1, str1, str2,dp);
        else
            dp[ind1][ind2] =  1 + min(solve(ind1 - 1, ind2 - 1, str1, str2,dp),
                           min(solve(ind1 - 1, ind2, str1, str2,dp),
                               solve(ind1, ind2 - 1, str1, str2,dp)));
                               
        return dp[ind1][ind2];
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n - 1, m - 1, word1, word2,dp);
    }

    int main() {

    string s1 = "horse";
    string s2 = "ros";

    cout << "The minimum number of operations required is: "<<minDistance(s1,s2);
    }
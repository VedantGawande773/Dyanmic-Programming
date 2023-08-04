#include <bits/stdc++.h>
using namespace std;

    int solve(int ind,int buy,int n,vector<int> &prices,vector<vector<int>>&dp){
        ///base case
        if(ind >= n) return 0;

        if(dp[ind][buy] != -1)
            return dp[ind][buy];

        int profit;

        if (buy == 0) {
            profit = max(-prices[ind] + solve(ind + 1, 1, n, prices, dp),
                        0 + solve(ind + 1, 0, n, prices, dp));
        } 
        
        if(buy == 1){
            profit = max(prices[ind] + solve(ind + 2, 0, n, prices, dp),
                        0 + solve(ind + 1, 1, n, prices, dp));
        }

        return dp[ind][buy] = profit;

    }

    int stockProfit(vector<int> &prices){
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 0, n, prices, dp);
    }

    int main() {

    vector<int> prices {4,9,0,4,10};
                                    
    cout<<"The maximum profit that can be generated is "<<stockProfit(prices);
    }
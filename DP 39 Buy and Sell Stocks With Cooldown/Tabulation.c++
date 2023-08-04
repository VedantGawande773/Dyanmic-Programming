    #include <bits/stdc++.h>
    using namespace std;

    int stockProfit(vector<int> &prices){
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2,0));

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
            int profit;

                if (buy == 0) {
                    profit = max(-prices[ind] + dp[ind + 1][1], 0 + dp[ind + 1][0]);                
                } 
                
                if(buy == 1){
                    profit = max(prices[ind] + dp[ind + 2][0],  0 + dp[ind + 1][1]);
                }

                 dp[ind][buy] = profit;                
            }
        }

        return dp[0][0];
    }

   int main() {

    vector<int> prices {4,9,0,4,10};
                                    
    cout<<"The maximum profit that can be generated is "<<stockProfit(prices);
    }
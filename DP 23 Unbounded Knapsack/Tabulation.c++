#include <bits/stdc++.h> 
using namespace std;

int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>>dp(n,vector<int>(W+1,0));
   //base case
    for(int i=wt[0]; i<=W; i++){
        dp[0][i] = ((int) i/wt[0]) * val[0];
    }

    for(int ind=1;ind<n;ind++){
        for(int target=0;target<=W;target++){
            int notTaken = 0 + dp[ind-1][target];
            int taken = INT_MIN;
            if(wt[ind] <= target)
                taken = val[ind] + dp[ind][target-wt[ind]];

             dp[ind][target] = max(taken,notTaken);
                }
    }
    return dp[n-1][W];
}

int main() {
  vector<int> wt = {2,4,6};
  vector<int> val = {5,11,13};
  int W=10;
  int n = wt.size();                      
  cout<<"The Maximum value of items, thief can steal is " <<unboundedKnapsack
  (n,W,val,wt);
}
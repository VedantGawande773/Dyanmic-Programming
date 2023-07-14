#include <bits/stdc++.h> 
using namespace std;

int solve(int ind,int W,vector<int> &val, vector<int> &wt,vector<vector<int>> &dp){
    //base case
    if(ind == 0){
        return (W/wt[0]) * val[0];
    }

    if(dp[ind][W] != -1)
        return dp[ind][W];

    int notTaken = 0 + solve(ind-1,W,val,wt,dp);
    int taken = INT_MIN;
    if(wt[ind] <= W)
        taken = val[ind] + solve(ind,W-wt[ind],val,wt,dp);

    return dp[ind][W] = max(taken,notTaken);
}

int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>>dp(n,vector<int>(W+1,-1));
    return solve(n-1,W,profit,weight,dp);
}

int main() {
  vector<int> wt = {2,4,6};
  vector<int> val = {5,11,13};
  int W=10;
  int n = wt.size();                      
  cout<<"The Maximum value of items, thief can steal is " <<unboundedKnapsack
  (n,W,val,wt);
}
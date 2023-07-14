#include <bits/stdc++.h> 
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    //base case
    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }

    if(arr[0]<=k)
        dp[0][arr[0]] = true;

    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
         bool notTaken = dp[i-1][j];
         bool taken = false;
         if(arr[i]<=j)
            taken = dp[i-1][j-arr[i]];
       
        dp[i][j] = taken||notTaken;
         }
    }
        return dp[n-1][k];
}

int main() {

  vector<int> arr = {1,2,3,4};
  int k=4;
  int n = arr.size();
                                 
  if(subsetSumToK(n,k,arr))
    cout<<"Subset with given target found";
  else 
    cout<<"Subset with given target not found";
}
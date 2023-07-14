#include<bits/stdc++.h>
using namespace std;

bool solve(int ind,int target,vector<int> &arr,vector<vector<int>> &dp){
	//base case
	if(target == 0) 
		return false;

	if(ind == 0)	
		 return (arr[ind] == target);

	if(dp[ind][target] != -1)
	 return dp[ind][target];

	 bool notTaken = solve(ind-1,target,arr,dp);
	 bool taken = false;
	 if(arr[ind] <= target)
	 	taken = solve(ind-1,target-arr[ind],arr,dp);

	return dp[ind][target] = taken||notTaken;
}

bool canPartition(vector<int> &arr, int n)
{
	int tsum = 0;

	for(int i=0;i<n;i++){
		tsum += arr[i];
	}
	
	if(tsum % 2 == 1) return false;
	else{
		int k = tsum/2;
		vector<vector<int>>dp(n,vector<int>(k+1,-1));
		return solve(n-1,k,arr,dp);
		}
}

int main() {

  vector<int> arr = {2,3,3,3,4,5};
  int n = arr.size();
                                 
  if(canPartition(arr,n))
    cout<<"The Array can be partitioned into two equal subsets";
  else 
    cout<<"The Array cannot be partitioned into two equal subsets";

    return 0;
}

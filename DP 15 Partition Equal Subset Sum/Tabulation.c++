#include<bits/stdc++.h>
using namespace std;

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
		
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }

        if(arr[0] <= k)
            dp[0][arr[0]] = true;
        
        for(int ind = 1; ind<n; ind++){
            for(int target= 1; target<=k; target++){
                
                bool notTaken = dp[ind-1][target];
        
                bool taken = false;
                    if(arr[ind]<=target)
                        taken = dp[ind-1][target-arr[ind]];
            
                dp[ind][target]= notTaken||taken;
            }
        }
        
        return dp[n-1][k];
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

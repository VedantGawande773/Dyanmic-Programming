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
		 vector<bool> prev(k+1,false);
    
        prev[0] = true;
		
        for(int i=0;i<n;i++){
            prev[0] = true;
        }

        if(arr[0] <= k)
            prev[arr[0]] = true;
        
        for(int ind = 1; ind<n; ind++){
            vector<bool> cur(k+1,false);
            cur[0] = true;
            for(int target= 1; target<=k; target++){
                
                bool notTaken = prev[target];
        
                bool taken = false;
                    if(arr[ind]<=target)
                        taken = prev[target-arr[ind]];
            
                cur[target]= notTaken||taken;
            }
             prev = cur;
        }
        
        return prev[k];
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

#include <bits/stdc++.h> 
using namespace std;

int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt)
{
    
    vector<int>curr(W+1,0);

   //base case
    for(int i=wt[0]; i<=W; i++){
       curr[i] = ((int) i/wt[0]) * val[0];
    }

    for(int ind=1;ind<n;ind++){
        for(int target=0;target<=W;target++){
            int notTaken = 0 + curr[target];
            int taken = INT_MIN;
            if(wt[ind] <= target)
                taken = val[ind] +curr[target-wt[ind]];

            curr[target] = max(taken,notTaken);
                }
    }
    return curr[W];
}

int main() {
  vector<int> wt = {2,4,6};
  vector<int> val = {5,11,13};
  int W=10;
  int n = wt.size();                      
  cout<<"The Maximum value of items, thief can steal is " <<unboundedKnapsack
  (n,W,val,wt);
}
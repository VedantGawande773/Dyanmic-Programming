#include <bits/stdc++.h> 
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr){
    
    //base case
    vector<bool> prev(k+1,false);
   
        prev[0] = true;
    

    if(arr[0]<=k)
        prev[arr[0]] = true;

    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            vector<bool> curr(k+1,false);
            curr[0] = true;
         bool notTaken = prev[j];
         bool taken = false;
         if(arr[i]<=j)
            taken = prev[j-arr[i]];
       
        curr[j] = taken||notTaken;
        prev = curr;
         }
    }
        return prev[k];
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
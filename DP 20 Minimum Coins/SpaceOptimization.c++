#include <bits/stdc++.h>
using namespace std;

int minimumElements(vector<int>& arr, int T){
    int n= arr.size();
    vector<int> prev(T+1,0), cur(T+1,0);
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            prev[i] = i/arr[0];
        else prev[i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + prev[target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + cur[target - arr[ind]];           
             cur[target] = min(notTake, take);
        }
        prev = cur;
    }
    
    int ans = prev[T];
    if(ans >=1e9) return -1;
    return ans;
}


int main() {
  vector<int> arr ={1,2,3};
  int T=7;                            
  cout<<"The minimum number of coins required to form the target sum is " 
  <<minimumElements(arr,T);
}
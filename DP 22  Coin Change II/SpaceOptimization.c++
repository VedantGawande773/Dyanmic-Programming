#include <bits/stdc++.h>
using namespace std;

long countWaysToMakeChange(vector<int>& arr, int n, int T){
    
    vector<long>prev(T+1,0);
    vector<long>curr(T+1,0);
    
    //Initializing base condition
    for(int i=0;i<=T;i++){
        if(i%arr[0]==0)
            prev[i]=1;
        // Else condition is automatically fulfilled,
        // as dp array is initialized to zero
    }
    
    for(int ind=1; ind<n;ind++){
        for(int target=0;target<=T;target++){
            long notTaken = prev[target];  
            long taken = 0;
            if(arr[ind]<=target)
                taken = curr[target-arr[ind]];         
            curr[target] = notTaken + taken;
        }
        prev = curr;
    }  
    return prev[T];
}

int main() {
  vector<int> arr ={1,2,3};
  int target=4;
  int n =arr.size();                         
  cout<<"The total number of ways is " <<countWaysToMakeChange(arr,n,target);
}
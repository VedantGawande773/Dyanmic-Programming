#include <bits/stdc++.h>
using namespace std;

int cutRod(vector<int>& price,int N) {
    vector<int> curr(N+1,0);
    
    for(int i=0;i<=N;i++){
        curr[i] = i*price[0];
    }

    for(int ind=1;ind<N;ind++){
        for(int length=0;length<=N;length++){
            int notTaken = 0 + curr[length];
            int taken = INT_MIN;
            int rodLength = ind+1;
            if(rodLength <= length)
                taken = price[ind] + curr[length-rodLength];
                
             curr[length] = max(notTaken,taken);       
        }
    }
        return curr[N];
}

int main() {
  vector<int> price = {2,5,7,8,10}; 
  int n = price.size();                           
  cout<<"The Maximum price generated is "<<cutRod(price,n);
}
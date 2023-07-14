#include <bits/stdc++.h> 
using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n)
{
 int totSum = 0;

  for (int i = 0; i < n; i++) {
    totSum += arr[i];
  }

 vector < bool > prev(totSum + 1, false);
  prev[0] = true;

  for(int i=0;i<n;i++){
    prev[0] = true;
  }

  if(arr[0] <= totSum)
    prev[totSum] = true;

for(int ind=1;ind<n;ind++){
     vector < bool > curr(totSum + 1, false);
    curr[0] = true;
    for(int target=1;target<=totSum;target++){
        	bool notTaken = prev[target];
            bool taken = false;
            if(arr[ind] <= target)
                taken = prev[target-arr[ind]];

		 curr[target] = taken || notTaken;
    }
    prev = curr;
}

  int mini = 1e9;
  for (int i = 0; i <= totSum; i++) {
    if (prev[i] == true) {
      int diff = abs(i - (totSum - i));
      mini = min(mini, diff);
    }
  }
  return mini;
}

int main() {

  vector < int > arr = {1,2,3,4};
  int n = arr.size();

  cout << "The minimum absolute difference is: " << minSubsetSumDifference(arr, n);

}
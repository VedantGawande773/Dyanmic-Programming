#include <bits/stdc++.h> 
using namespace std;

int solve(int ind,vector<int> &nums,vector<int> &dp){
    if(ind == 0) return nums[ind];
    if(ind < 0) return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int pick = nums[ind] + solve(ind-2,nums,dp);
    int notPick = 0 + solve(ind-1,nums,dp);
    dp[ind] = max(pick,notPick);
    return dp[ind];

}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n+1,-1);
    return solve(n-1,nums,dp);
}

int main() {
    vector<int> nums = {2, 1, 9, 1, 10};
    int result = maximumNonAdjacentSum(nums);
    cout << "Maximum Non-Adjacent Sum: " << result << endl;
    return 0;
}
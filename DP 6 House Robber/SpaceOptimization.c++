#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumNonAdjacentSum(vector<int> &nums){
        int n = nums.size();

        int prev = nums[0];
        int prev2 = 0;

        for(int i = 1; i < n; i++){
            int pick = nums[i];
            if(i > 1)
                pick += prev2;
            int nonPick = 0 + prev;

            int cur_i = max(pick, nonPick);
            prev2 = prev;
            prev = cur_i;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp1, temp2;
        if(n == 1) return nums[0];
        for(int i = 0; i < n; i++){
            if(i != 1) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        return max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum(temp2));
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 3, 2};
    int result = solution.rob(nums);
    cout << "Maximum Robbed Amount: " << result << endl;
    return 0;
}

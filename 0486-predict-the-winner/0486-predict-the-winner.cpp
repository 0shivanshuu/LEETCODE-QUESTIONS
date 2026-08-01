class Solution {
public:
    int solve(vector<int>& nums, int low, int high,
              vector<vector<int>>& dp) {

        if(low == high){
            return nums[low];
        }

        if(dp[low][high] != INT_MIN){
            return dp[low][high];
        }

        int pickLeft = nums[low] - solve(nums, low + 1, high, dp);
        int pickRight = nums[high] - solve(nums, low, high - 1, dp);

        return dp[low][high] = max(pickLeft, pickRight);
    }

    bool predictTheWinner(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(
            n, vector<int>(n, INT_MIN)
        );

        return solve(nums, 0, n - 1, dp) >= 0;
    }
};
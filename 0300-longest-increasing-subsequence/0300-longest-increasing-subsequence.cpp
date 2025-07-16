class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int prev = i - 1; prev >= -1; prev--) {
                int notTake = dp[i + 1][prev + 1];
                int take = 0;
                if (prev == -1 || nums[i] > nums[prev]) {
                    take = 1 + dp[i + 1][i + 1];
                }
                dp[i][prev + 1] = max(take, notTake);
            }
        }

        return dp[0][0];
    }
};
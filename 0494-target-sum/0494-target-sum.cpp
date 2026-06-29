class Solution {
public:
    int func(int ind, vector<int>& nums, int target, vector<vector<int>>& dp, int offset) {
        if (target < -offset || target > offset) return 0;
        if (ind == 0) {
            if (target == 0 && nums[0] == 0)
                return 2;
            if (target == nums[0] || target == -nums[0])
                return 1;
            return 0;
        }

        if (dp[ind][target + offset] != -1)
            return dp[ind][target + offset];

        int takePlus = func(ind - 1, nums, target - nums[ind], dp, offset);
        int takeMinus = func(ind - 1, nums, target + nums[ind], dp, offset);

        return dp[ind][target + offset] = takePlus + takeMinus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = 0;
        for (int x : nums)
            sum += x;

        if (abs(target) > sum)
            return 0;

        vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1));

        return func(n - 1, nums, target, dp, sum);
    }
};

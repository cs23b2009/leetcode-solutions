class Solution {
public:
    int func(int ind, vector<int>& nums, int target) {
        if (ind == 0) {
            if (target == 0 && nums[0] == 0)
                return 2;
            if (target == nums[0] || target == -nums[0])
                return 1;
            return 0;
        }
        return func(ind - 1, nums, target - nums[ind]) +
               func(ind - 1, nums, target + nums[ind]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return func(nums.size() - 1, nums, target);
    }
};
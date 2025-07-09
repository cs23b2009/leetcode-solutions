class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int l = 0 , cnt = 0;
        int sum = 0;
        for (int r = 0; r < nums.size(); ++r) {
            sum += (nums[r] % 2);  
            while (sum > goal) {
                sum -= (nums[l++] % 2);
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};
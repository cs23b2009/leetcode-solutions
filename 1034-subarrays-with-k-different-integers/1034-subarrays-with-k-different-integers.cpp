class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int l = 0, sum = 0, cnt = 0;
        unordered_map<int,int> mpp;
        for (int r = 0; r < nums.size(); ++r) {
            mpp[nums[r]]++;
            while (mpp.size() > goal) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);  // \U0001f527 Fixed here
                }
                l++;
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};
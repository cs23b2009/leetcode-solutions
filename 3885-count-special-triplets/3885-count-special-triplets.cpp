class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> right, left;
        for (int num : nums) {
            right[num]++;
        }

        long long res = 0;
        int n = nums.size();
        
        for (int j = 0; j < n; ++j) {
            right[nums[j]]--; // current j is no longer in right
            
            int target = nums[j] * 2;
            int count_i = left[target];
            int count_k = right[target];

            res = (res + 1LL * count_i * count_k) % MOD;

            left[nums[j]]++; // include current j in left
        }
        
        return res;
    }
};
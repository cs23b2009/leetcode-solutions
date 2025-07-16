class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);  // To store predecessors
        int maxi = 1, lastIndex = 0;

        for(int i = 0; i < n; i++) {
            hash[i] = i; // initially point to self
            for(int prev = 0; prev < i; prev++) {
                if(nums[prev] < nums[i] && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        // Reconstruct LIS
        vector<int> lis;
        while(hash[lastIndex] != lastIndex) {
            lis.push_back(nums[lastIndex]);
            lastIndex = hash[lastIndex];
        }
        lis.push_back(nums[lastIndex]);

        reverse(lis.begin(), lis.end());
        for(int num : lis) {
            cout << num << " ";
        }
        cout << endl;

        return maxi;
    }
};
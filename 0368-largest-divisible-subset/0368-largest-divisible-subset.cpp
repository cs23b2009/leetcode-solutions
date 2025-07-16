class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n, 1);
        vector<int> hash(n); 
        int maxi = 1, lastIndex = 0;
        for(int i = 0; i < n; i++) {
            hash[i] = i; 
            for(int prev = 0; prev < i; prev++) {
                if(nums[i] % nums[prev] == 0 && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<int> lis;
        while(hash[lastIndex] != lastIndex) {
            lis.push_back(nums[lastIndex]);
            lastIndex = hash[lastIndex];
        }
        lis.push_back(nums[lastIndex]);

        reverse(lis.begin(), lis.end());
        return lis;
    }
};
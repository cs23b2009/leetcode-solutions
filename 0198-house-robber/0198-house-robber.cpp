class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        dp[0] = nums[0];
        for(int i=1;i<n;i++){
            int pick = nums[i];
            int nonpick = INT_MIN;
            if(i>1) pick += dp[i-2];
            if(i>0) nonpick = dp[i-1];
            dp[i] = max(pick,nonpick);
        }
        return dp[n-1];
    }
};
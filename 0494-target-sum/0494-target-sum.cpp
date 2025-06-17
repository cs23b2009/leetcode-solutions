class Solution {
    int memoization(int i,vector<int>& nums,vector<vector<int>>& dp,int s,int target){
        if(i<0){
            if(s==target) return 1;
            return 0;
        }
        if(dp[i][s+1000]!=-1) return dp[i][s+1000];
        int add=memoization(i-1,nums,dp,s+nums[i],target);
        int sub=memoization(i-1,nums,dp,s-nums[i],target);
        return dp[i][s+1000]=add+sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2001,-1));
        return memoization(n-1,nums,dp,0,target);
    }
};
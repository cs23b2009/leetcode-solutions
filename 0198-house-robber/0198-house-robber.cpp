class Solution {
public:

    int recur(int index,vector<int>& nums,vector<int>&dp){

        if(index==0) return nums[0];

        if(index<0) return 0;
        if(dp[index]!=-1) return dp[index];
        int pick = recur(index-2,nums,dp) + nums[index];

        int notPick = recur(index-1,nums,dp);

        return dp[index] = max(pick,notPick);
    }

    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return recur(nums.size()-1,nums,dp);
    }
};
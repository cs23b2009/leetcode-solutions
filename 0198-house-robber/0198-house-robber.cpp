class Solution {
public:
    int recur(vector<int>nums,int n,vector<int>&dp){
        if(n<0) return INT_MIN;
        if(dp[n]!=-1) return dp[n];
        int taken = nums[n];
        if(n>1) {
            taken += recur(nums,n-2,dp);
        }
        int nottaken = INT_MIN;
        if(n>0){
            nottaken = recur(nums,n-1,dp);
        }
        return dp[n]= max(taken,nottaken);
    }
    int rob(vector<int>& nums) {
        int n =  nums.size()-1;
        vector<int>dp(n+1,-1);
        return recur(nums,n,dp);
    }
};
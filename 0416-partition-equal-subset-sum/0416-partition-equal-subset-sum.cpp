class Solution {
public:
    bool recur(int index,vector<int>&nums,int sum,vector<vector<int>>&dp){
        if(sum==0){
            return true;
        }
        if(index==nums.size()){
            return false;
        }
        if(dp[index][sum]!=-1) return dp[index][sum];
        bool pick = false;
        if(nums[index]<=sum){
            pick = recur(index+1,nums,sum-nums[index],dp);
        }
        bool nonpick = recur(index+1,nums,sum,dp);
        return dp[index][sum] = pick||nonpick;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        if(sum%2==0){
            sum /= 2;
        }
        else{
            return false;
        }
        vector<vector<int>>dp(nums.size(),vector<int>(sum+1,-1));
        return recur(0,nums,sum,dp);
    }
};
class Solution {
public:
    int func(int start,int sum,vector<int> &nums,vector<vector<int>>&dp){
        if(sum==0) return true;
        if(start<0) return false;
        if(start==0) return sum==nums[0];
        if(dp[start][sum]!=-1) return dp[start][sum];
        int nottaken = func(start-1,sum,nums,dp);
        int taken = false;
        if(sum>=nums[start]){
            taken = func(start-1,sum-nums[start],nums,dp);
        }
return dp[start][sum] = nottaken || taken;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum%2==1){
            return false;
        }
        sum = sum/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return func(n-1,sum,nums,dp);
    }
};
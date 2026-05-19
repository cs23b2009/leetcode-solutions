class Solution {
public:
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
        vector<vector<bool>>dp(nums.size(),vector<bool>(sum+1,false));
        for(int i=0;i<nums.size();i++){
            dp[i][0] = true;
        }
        if(nums[0]<=sum){
            dp[0][nums[0]] = true;
        }
        for(int i=1;i<nums.size();i++){
            for(int j=1;j<=sum;j++){
                bool pick = false;
                if(j>=nums[i]){
                    pick = dp[i-1][j-nums[i]];
                }
                bool nonpick = dp[i-1][j];
                dp[i][j] = pick || nonpick;
            }
        }
        return dp[nums.size()-1][sum];
    }
};
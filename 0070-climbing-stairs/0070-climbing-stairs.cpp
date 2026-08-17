class Solution {
public:
    int recur(int n,vector<int>&dp){
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        if(n>1){
            return dp[n]=recur(n-1,dp)+recur(n-2,dp);
        }
        else{
            return dp[n]=recur(n-1,dp);
        }
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
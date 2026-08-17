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
        vector<int>dp(n+1,-1);
        return recur(n,dp);
    }
};
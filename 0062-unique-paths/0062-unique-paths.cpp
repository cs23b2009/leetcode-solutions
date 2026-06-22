class Solution {
public:
    int func(int m,int n,vector<vector<int>>&dp){
        if(m<0 || n<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        if(m==0&&n==0) return 1;
        return dp[m][n]=func(m-1,n,dp) + func(m,n-1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(m-1,n-1,dp);
    }
};
class Solution {
public:
    int func(int n , vector<int>&dp){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int minsteps = INT_MAX;
        for(int i=1;i*i<=n;i++){
            if(i*i<=n){
                minsteps = min(minsteps,1 + func(n-i*i , dp));
            }
        }
        return dp[n] = minsteps;
    }
    int numSquares(int n) {
        for(int i=0;i*i<=n;i++){
            if(i*i==n) return 1;
        }
        vector<int> dp(n+1,-1);
        return func(n , dp);
    }
};
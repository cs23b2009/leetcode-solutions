class Solution {
public:
    int func(int n,int m,string &s, string &t,vector<vector<int>>& dp){
        if(m==t.size()) return 1;
        if(n==s.size()) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s[n]==t[m]){
            int taken = func(n+1,m+1,s,t,dp);
            int nottaken = func(n+1,m,s,t,dp);
            return dp[n][m]=taken+nottaken;
        }
        else{
            return dp[n][m]=func(n+1,m,s,t,dp);
        }
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return func(0,0,s,t,dp);
    }
};
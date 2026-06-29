class Solution {
public:
    int func(int n , int m,string& s1,string& s2,vector<vector<int>>& dp){
        if(n<0 || m<0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s1[n]==s2[m]) {
            return dp[n][m] = 1 + func(n-1,m-1,s1,s2,dp);
        }
        else{
            return dp[n][m]=max(func(n-1,m,s1,s2,dp),func(n,m-1,s1,s2,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s1 = s;
        string s2 = "";
        for(int i=n-1;i>=0;i--){
            s2 += s1[i];
        }
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return func(n-1,n-1,s1,s2,dp);
    }
};
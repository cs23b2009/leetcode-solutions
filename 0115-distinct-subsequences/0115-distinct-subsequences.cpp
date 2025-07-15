class Solution {
public:
    int func(string s, string t, int i, int j, vector<vector<int>> &dp){
        if(j < 0) return 1;    
        if(i < 0) return 0;    

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]){
            return dp[i][j] = func(s,t,i-1,j,dp) + func(s,t,i-1,j-1,dp);
        }
        else{
            return dp[i][j] = func(s,t,i-1,j,dp);
        }
    }

    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return func(s, t, n - 1, m - 1, dp);
    }
};
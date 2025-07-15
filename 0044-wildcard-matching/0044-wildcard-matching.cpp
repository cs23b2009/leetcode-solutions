class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, 0));
        dp[0][0] = 1;
        for (int j = 1; j <= n; j++) {
            bool bl=true;
            for (int k = j; k > 0; k--) {
                if (p[k - 1] != '*') {
                    bl=false;
                }
            }
            dp[0][j]=bl;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
}
};
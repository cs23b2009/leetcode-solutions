class Solution {
public:
    int minCost(int n, vector<int>& arr) {
        int N = arr.size();
        vector<int> cuts = arr;
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int len = 2; len < m; len++) {
            for (int i = 0; i + len < m; i++) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
                }
            }
        }

        return dp[0][m - 1];
    }
};
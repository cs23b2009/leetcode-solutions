class Solution {
public:
    int func(vector<vector<int>>& grid, vector<vector<vector<int>>> &dp, int i, int j1, int j2) {
        int n = grid.size(), m = grid[0].size();

        // Boundary check
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return INT_MIN;

        // Check memoization
        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

        // Base case
        if (i == n - 1) {
            return dp[i][j1][j2] = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
        }

        int maxCherries = INT_MIN;
        for (int dj1 = -1; dj1 <= 1; ++dj1) {
            for (int dj2 = -1; dj2 <= 1; ++dj2) {
                int nextJ1 = j1 + dj1;
                int nextJ2 = j2 + dj2;
                int result = func(grid, dp, i + 1, nextJ1, nextJ2);
                maxCherries = max(maxCherries, result);
            }
        }

        int currCherries = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
        return dp[i][j1][j2] = currCherries + maxCherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1))); // use -1 for memo
        return func(grid, dp, 0, 0, m - 1);
    }
};
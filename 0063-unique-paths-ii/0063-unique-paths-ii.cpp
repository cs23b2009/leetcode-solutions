class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<int> prev(n, 0);
        
        
        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[0][j] == 1) break;  // obstacle encountered, rest are unreachable
            prev[j] = 1;
        }
        
        for (int i = 1; i < m; ++i) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    curr[j] = 0;
                } else {
                    if (j > 0) {
                        curr[j] = curr[j - 1] + prev[j];
                    } else {
                        curr[j] = prev[j];
                    }
                }
            }
            prev = curr;
        }
        
        return obstacleGrid[m-1][n-1] == 1 ? 0 : prev[n - 1];
    }
};
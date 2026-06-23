class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1) return 0;

        vector<int> past(n, 0);

        for(int i = 0; i < m; i++) {
            vector<int> present(n, 0);

            for(int j = 0; j < n; j++) {

                if(obstacleGrid[i][j] == 1) {
                    present[j] = 0;
                    continue;
                }

                if(i == 0 && j == 0) {
                    present[j] = 1;
                    continue;
                }

                int up = (i > 0) ? past[j] : 0;
                int left = (j > 0) ? present[j - 1] : 0;

                present[j] = up + left;
            }

            past = present;
        }

        return past[n - 1];
    }
};
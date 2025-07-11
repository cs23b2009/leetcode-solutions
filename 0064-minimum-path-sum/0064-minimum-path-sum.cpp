class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = 0;
        for(int i=0;i<m;i++){
            ans += grid[0][i];
            dp[0][i] = ans;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int left = INT_MAX;
                int up = dp[i-1][j] ;
                if(j>0) left = dp[i][j-1];
                dp[i][j] = min(left,up) + grid[i][j] ;
            }
        }
        return dp[n-1][m-1];
    }
};
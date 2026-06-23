class Solution {
public:
    int func(vector<vector<int>> obstacleGrid,int row,int col,vector<vector<int>> &dp){
        if(row<0 || row >obstacleGrid.size() || col<0 || col > obstacleGrid[0].size() ) return 0;
        if(obstacleGrid[row][col]==1 ) return 0;
        if(row==0 && col==0) return 1;
        if(dp[row][col]!=-1) return dp[row][col];
        return dp[row][col] = func(obstacleGrid,row-1,col,dp) + func(obstacleGrid,row,col-1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return func(obstacleGrid,m-1,n-1,dp);
    }
};
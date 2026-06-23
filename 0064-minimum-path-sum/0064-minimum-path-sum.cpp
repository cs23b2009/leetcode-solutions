class Solution {
public:
    int func(vector<vector<int>>& grid,int row,int col,vector<vector<int>>&dp){
        if(row<0 || col <0) return 1e9;
        if(row==0 && col==0) return grid[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        return dp[row][col]=grid[row][col] + min(func(grid,row-1,col,dp),func(grid,row,col-1,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return func(grid,m-1,n-1,dp);
    }
};
class Solution {
public:
    int func(vector<vector<int>>& triangle,int row,int col,vector<vector<int>>&dp){
        if(row<0 || col<0 || col>row) return 1e9;
        if(row==0 && col==0) return triangle[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        int up = 1e9;
        int upright = 1e9;
        if(row>0 && col>0){
            upright = func(triangle,row-1,col-1,dp);
        }
        if(row>0){
            up = func(triangle,row-1,col,dp);
        }
        return  dp[row][col]=triangle[row][col]+min(upright,up);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans = INT_MAX;
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle.size(),-1));
        for(int i=0;i<triangle.size();i++){
            ans = min(ans,func(triangle,triangle.size()-1,i,dp));
        }
        return ans;
    }
};
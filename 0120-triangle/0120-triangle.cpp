class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int ans = INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        dp[0][0] = triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                int up = 1e9;
                int upright = 1e9;
                if(i>0 && j>0){ upright = dp[i-1][j-1]; }
                if(i>0){ up = dp[i-1][j]; }
                dp[i][j] = triangle[i][j] + min(up,upright);
            }
        }
        for(int i=0;i<n;i++){
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
    }
};
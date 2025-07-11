#include <algorithm>
#include <vector>
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n  = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0] = triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                int up = INT_MAX;
                if(i!=j) up = dp[i-1][j];
                int upleft = INT_MAX;
                if(j>0) upleft = dp[i-1][j-1];
                dp[i][j] = min(up,upleft) + triangle[i][j];
            }
        }
        int mini = INT_MAX;
        for(int i=0;i<m;i++){
            mini = min(mini,dp[n-1][i]);
        }
        return mini;
    }

};
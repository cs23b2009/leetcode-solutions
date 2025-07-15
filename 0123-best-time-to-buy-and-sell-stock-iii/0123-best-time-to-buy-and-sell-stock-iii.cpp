class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i= prices.size()-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=1;k<3;k++){
                    if(j==1){
                        int profit = -prices[i] + dp[i+1][0][k];
                       int skip = dp[i+1][1][k];
                        dp[i][j][k] = max(profit , skip);
                    }
                    else{
                        int sell = prices[i] + dp[i+1][1][k-1];
                        int skip = dp[i+1][0][k];
                        dp[i][j][k]=max(sell,skip);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};
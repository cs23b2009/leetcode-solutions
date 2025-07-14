class Solution {
public:
   
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i=1;i<prices.size();i++){
            for(int j=0;j<2;j++){
                if(j==0){
                    int sell = prices[i] + dp[i-1][1];
                    int skip = dp[i-1][0];
                   dp[i][j] = max(sell,skip);
                }
                else{
                    int buying = -prices[i] + dp[i-1][0];
                    int skip = dp[i-1][1];
                    dp[i][j] = max(buying,skip);
                }
            }
        }
        return max(dp[prices.size()-1][0],dp[prices.size()-1][1]);
    }
};
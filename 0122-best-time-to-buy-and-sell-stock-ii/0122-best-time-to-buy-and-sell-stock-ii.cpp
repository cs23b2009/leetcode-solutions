class Solution {
public:
    int func(vector<int>& prices,int buy,int start,vector<vector<int>> &dp){
        if(start==prices.size()) return 0;
        if(dp[start][buy]!=-1) return dp[start][buy];
        int profit = 0;
        if(buy==0){
            profit = max(func(prices,buy,start+1,dp),-prices[start]+func(prices,!buy,start+1,dp));
        }
        else{
            profit = max(func(prices,buy,start+1,dp),prices[start]+func(prices,!buy,start+1,dp));
        }
        return dp[start][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return func(prices,0,0,dp);
    }
};
class Solution {
public:
    int func(vector<int>& coins, int amount,vector<int> &dp) {
        if (amount == 0)
            return 0;

        if (amount < 0)
            return INT_MAX;

        int mini = INT_MAX;
        if(dp[amount]!=-1) return dp[amount];
        for (int i = 0; i < coins.size(); i++) {
            int res = func(coins, amount - coins[i],dp);

            if (res != INT_MAX){
                    mini = min(mini, 1 + res);
            }
        }

        return dp[amount]=mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans = func(coins, amount,dp);
        return ans == INT_MAX ? -1 : ans;
    }
};
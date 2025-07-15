class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prev1(2, 0);
        vector<int> prev2(2, 0);
        for (int ind = n - 1; ind >= 0; ind--) {
            vector<int> curr(2, 0);
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    int take = -prices[ind] + prev1[0];
                    int skip = prev1[1];
                    curr[1] = max(take, skip);
                } else {
                    int take = prices[ind] + prev2[1];
                    int skip = prev1[0];
                    curr[0] = max(take, skip);
                }
            }
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1[1];
    }
};
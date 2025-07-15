class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int ans = 0;
        for(int i=1;i<prices.size();i++){
            int profit = prices[i] - mini;
            ans = max(ans,profit);
            mini = min(mini , prices[i]);
        }
        return ans;
    }
};
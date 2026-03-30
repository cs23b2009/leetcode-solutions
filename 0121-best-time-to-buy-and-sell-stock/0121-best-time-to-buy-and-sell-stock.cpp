class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ele = INT_MAX;
        int profit = 0;
        for(int i=0;i<prices.size();i++){
            ele = min(ele,prices[i]);
            profit = max(prices[i]-ele,profit);
        }
        return profit;
    }
};
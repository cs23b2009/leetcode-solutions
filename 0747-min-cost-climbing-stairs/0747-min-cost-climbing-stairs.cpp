class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 2) return min(cost[0], cost[1]);

        vector<int> ans(n + 1, INT_MAX);

        ans[0] = 0;
        ans[1] = 0;

        for(int i = 2; i <= n; i++) {
            ans[i] = min(ans[i - 1] + cost[i - 1], ans[i - 2] + cost[i - 2]);
        }

        return ans[n];
    }
};
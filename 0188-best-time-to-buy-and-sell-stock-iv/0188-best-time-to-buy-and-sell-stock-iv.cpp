class Solution {
public:
    int maxProfit(int k , vector<int>& prices) {
        if(k==1){
            int mini = prices[0];
        int ans = 0;
        for(int i=1;i<prices.size();i++){
            int profit = prices[i] - mini;
            ans = max(ans,profit);
            mini = min(mini , prices[i]);
        }
        return ans;
        }
        vector<vector<int>> prev(2,vector<int>(k+1,0));
        for(int i= prices.size()-1;i>=0;i--){
            vector<vector<int>> curr(2,vector<int>(k+1,0));
            for(int j=0;j<2;j++){
                for(int cap=1;cap<k+1;cap++){
                    if(j==1){
                        int profit = -prices[i] + prev[0][cap];
                       int skip = prev[1][cap];
                        curr[j][cap] = max(profit , skip);
                    }
                    else{
                        int sell = prices[i] + prev[1][cap-1];
                        int skip = prev[0][cap];
                        curr[j][cap]=max(sell,skip);
                    }
                }
            }
            prev = curr;
        }
        return prev[1][k];
    }
};
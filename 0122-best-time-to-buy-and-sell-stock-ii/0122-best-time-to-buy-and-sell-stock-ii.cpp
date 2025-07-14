class Solution {
public:
   
    int maxProfit(vector<int>& prices) {
        vector<int> prev(2,-1);
        prev[0] = 0;
        prev[1] = -prices[0];
        for(int i=1;i<prices.size();i++){
            vector<int> curr(2,-1);
            for(int j=0;j<2;j++){
                if(j==0){
                    int sell = prices[i] + prev[1];
                    int skip = prev[0];
                   curr[j] = max(sell,skip);
                }
                else{
                    int buying = -prices[i] + prev[0];
                    int skip = prev[1];
                    curr[j] = max(buying,skip);
                }
            }
            prev = curr;
        }
        return prev[0];
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices , int fee) {
        vector<int> prev(2,0);
        for(int ind=prices.size()-1;ind>=0;ind--){
            vector<int> curr(2,0);
            for(int j=0;j<2;j++){
                if(j==1){
                    int buy = -prices[ind] + prev[0];
                    int skip = prev[1];
                     curr[j] = max(buy,skip);
                }
                else{
                    int sell = prices[ind] -fee + prev[1];
                    int skip = prev[0];
                    curr[j] = max(sell,skip);
                }
            }
            prev = curr;
        }
        return prev[1];
    }
};
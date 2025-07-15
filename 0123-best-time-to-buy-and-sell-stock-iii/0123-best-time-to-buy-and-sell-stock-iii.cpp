class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> prev(2,vector<int>(3,0));
        for(int i= prices.size()-1;i>=0;i--){
            vector<vector<int>> curr(2,vector<int>(3,0));
            for(int j=0;j<2;j++){
                for(int k=1;k<3;k++){
                    if(j==1){
                        int profit = -prices[i] + prev[0][k];
                       int skip = prev[1][k];
                        curr[j][k] = max(profit , skip);
                    }
                    else{
                        int sell = prices[i] + prev[1][k-1];
                        int skip = prev[0][k];
                        curr[j][k]=max(sell,skip);
                    }
                }
            }
            prev = curr;
        }
        return prev[1][2];
    }
};
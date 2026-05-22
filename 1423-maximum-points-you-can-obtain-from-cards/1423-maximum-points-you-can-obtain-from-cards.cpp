class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftsum = 0;
        for(int i=0;i<k;i++){
            leftsum += cardPoints[i];
        }
        int ans = leftsum;
        int rightsum = 0;
        int index = k-1;
        for(int i=cardPoints.size()-1;i>cardPoints.size()-k-1;i--){
            rightsum += cardPoints[i];
            leftsum  -= cardPoints[index--];
            ans = max(ans,leftsum+rightsum); 
        }
        return ans;
    }
};
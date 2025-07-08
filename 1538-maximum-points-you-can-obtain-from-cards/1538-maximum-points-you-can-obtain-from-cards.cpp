class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftsum = 0;
        int rightsum = 0;
        for(int i=0;i<k;i++){
            leftsum += cardPoints[i];
        }
        int maxsum = leftsum;
        int index = cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            leftsum -= cardPoints[i];
            rightsum += cardPoints[index--];
            maxsum = max(maxsum,leftsum+rightsum);
        }
        return maxsum;
    }
};
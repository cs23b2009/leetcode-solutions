class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n,0);
        for(int i=0;i<n;i++){
            prev[i] = matrix[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                int down =  prev[j]  ;
                int left = (j>0) ? prev[j-1] : 1e5 ;
                int right = (j<n-1) ? prev[j+1] : 1e5;
                curr[j] = matrix[i][j] + min(down ,min(left,right));
            }
            prev = curr;
        }
        int minvalue = 1e5;
        for(int i=0;i<n;i++){
            minvalue = min(minvalue,prev[i]);
        }
        return minvalue ;
    }
};
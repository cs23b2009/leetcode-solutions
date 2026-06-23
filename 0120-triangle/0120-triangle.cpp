class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int ans = INT_MAX;
        vector<int>past(n,0);
        past[0] = triangle[0][0];
        for(int i=1;i<n;i++){
            vector<int>present(n,0);
            for(int j=0;j<=i;j++){
                int up = 1e9;
                int upright = 1e9;
                if(j>0){ upright = past[j-1]; }
                if(j<i){ up = past[j]; }
                present[j] = triangle[i][j] + min(up,upright);
            }
            past = present;
        }
        for(int i=0;i<n;i++){
            ans = min(ans,past[i]);
        }
        return ans;
    }
};
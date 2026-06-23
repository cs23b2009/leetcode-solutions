class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>past(n,0);
        for(int i=0;i<m;i++){
            vector<int>present(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) {
                    present[j] = grid[0][0];
                    continue;
                }
                int right = 1e9;
                int down = 1e9;
                if(i>0){
                    right = past[j];
                }
                if(j>0){
                    down = present[j-1];
                }
                present[j] = grid[i][j] + min(right,down);
            }
            past = present;
        }
        return past[n-1];
    }
};
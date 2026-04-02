class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int,int>> zeroes;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    zeroes.push_back({i,j});
                }
            }
        }
        for(auto it:zeroes){
            for(int i=0;i<n;i++){
                matrix[i][it.second] = 0;
            }
            for(int j=0;j<m;j++){
                matrix[it.first][j] = 0;
            }
        }
    }
};
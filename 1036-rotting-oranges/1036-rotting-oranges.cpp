class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int countfresh = 0;
        queue<pair<pair<int,int> , int>> ans;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    visited[i][j] = 2;
                    ans.push({{i, j}, 0});
                } else {
                    visited[i][j] = 0;
                }
                if(grid[i][j] == 1) countfresh++;
            }
        }

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        int cnt = 0;
        int t = 0;

        while(!ans.empty()){
            int nrow = ans.front().first.first;
            int ncol = ans.front().first.second;
            int time = ans.front().second;
            ans.pop();
            t = max(t, time);
            for(int i=0; i<4; i++){
                int nnrow = nrow + dr[i];
                int nncol = ncol + dc[i];
                if(nnrow >= 0 && nncol >= 0 && nnrow < n && nncol < m &&
                   grid[nnrow][nncol] == 1 && visited[nnrow][nncol] != 2){
                    ans.push({{nnrow, nncol}, time + 1});
                    visited[nnrow][nncol] = 2;
                    cnt++;
                }
            }
        }

        if(cnt != countfresh) return -1;
        return t;
    }
};
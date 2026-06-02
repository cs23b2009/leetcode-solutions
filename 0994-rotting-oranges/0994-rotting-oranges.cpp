class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        int time = 0;
        vector<int> roww = {-1,0,1,0};
        vector<int> coll = {0,1,0,-1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            time = max(time,it.second);
            for(int i=0;i<4;i++){
                int nr = it.first.first + roww[i];
                int nc = it.first.second + coll[i];
                if(nr>=0 && nr<n && nc >=0 && nc < m){
                    if(grid[nr][nc]==1){
                        grid[nr][nc] = 2;
                        q.push({{nr,nc},it.second+1});
                        ans--;
                    }
                }
            }
        }
        if(ans!=0){
            return -1;
        }
        return time;
    }
};
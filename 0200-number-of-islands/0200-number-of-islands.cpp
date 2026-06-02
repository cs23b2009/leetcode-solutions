class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<int> roww = {-1,0,1,0};
        vector<int> coll = {0,1,0,-1};
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j] =='1'){
                    ans++;
                    q.push({i,j});
                    while(!q.empty()){
                        auto it = q.front();
                        q.pop();
                        for(int i=0;i<4;i++){
                            int nr = it.first +roww[i];
                            int nc = it.second +coll[i];
                            if(nr>=0 && nr < n && nc>=0 && nc<m){
                                if(visited[nr][nc]==0 && grid[nr][nc] =='1'){
                                   visited[nr][nc] = 1;
                                   q.push({nr,nc}); 
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
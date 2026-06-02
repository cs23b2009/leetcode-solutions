class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       int n = mat.size();
       int m = mat[0].size();
       vector<vector<int>> visited(n,vector<int>(m,0));
       vector<vector<int>> distance(n,vector<int>(m,0));
       vector<int> roww = {-1,0,1,0};
       vector<int> coll = {0,1,0,-1};
       queue<pair<int,int>> q;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                visited[i][j]=1;
                q.push({i,j});
            }
        }
       }
       while(!q.empty()){
        auto it = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nr = it.first + roww[i];
            int nc = it.second + coll[i];
            if(nr>=0 && nr < n && nc>=0 && nc<m){
                if(!visited[nr][nc]){
                    visited[nr][nc] = 1;
                    distance[nr][nc] = distance[it.first][it.second] + 1;
                    q.push({nr,nc});
                }
            }
        }
       }
       return distance;
    }
};
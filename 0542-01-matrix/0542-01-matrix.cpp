class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mat[i][j] = !mat[i][j];
        }
    }
    vector<vector<int>> visited(n,(vector<int>(m,0)));
    vector<vector<int>> distance(n,(vector<int>(m,0)));
    queue<pair<pair<int,int>,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]){
                visited[i][j] = 1;
                q.push({{i,j},0});
            }
        }
    }
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1};
    while(!q.empty()){
        int node1 = q.front().first.first;
        int node2 = q.front().first.second;
        int dis =  q.front().second;
        q.pop();
        distance[node1][node2] = dis;
        for(int i=0;i<4;i++){
            int nrow = node1 + dr[i];
            int ncol = node2 + dc[i];
            if(nrow>=0 && ncol >=0 && nrow <n && ncol <m && visited[nrow][ncol]==0){
                q.push({{nrow,ncol},dis+1});
                visited[nrow][ncol] = 1;
            }
        }
    }
    return distance;
    }
};
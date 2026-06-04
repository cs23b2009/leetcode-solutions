class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n==1) return 1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>> distance(n,vector<int>(n,1e9));
        distance[0][0] = 1;
        pq.push({1,{0,0}});
        while(!pq.empty()){
            auto it = pq.top();
            int dist = it.first;
            int r = it.second.first;
            int c = it.second.second;
            pq.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(i==0 && j==0){
                        continue;
                    }
                        int nr = r + i;
                        int nc = c + j;
                        if(nr>=0 && nc >=0 && nr<n && nc<n && grid[nr][nc]==0){
                            if(nr==n-1 && nc==n-1){
                                return dist + 1;
                            }
                            if(dist+1<distance[nr][nc]){
                                distance[nr][nc] = dist+1;
                                pq.push({distance[nr][nc],{nr,nc}});
                            }
                        }
                }
            }
        }
        return -1;
    }
};
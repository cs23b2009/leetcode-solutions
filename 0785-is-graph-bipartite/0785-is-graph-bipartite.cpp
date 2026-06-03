class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,0);
        vector<int> colors(n,0);
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                q.push({i,0});
        visited[i] = 1;
        colors[i] = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int node = it.first;
            int color = it.second;
            for(auto neig : graph[node]){
                if(!visited[neig]){
                    visited[neig] = 1;
                    colors[neig] = !color;
                    q.push({neig,!color});
                }
                else{
                    if(colors[neig]==color){
                        return false;
                    }
                }
            }
        }
            }
        }
        return true;
    }
};
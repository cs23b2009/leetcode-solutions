class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>& visited,vector<int>&colors,int node,int color){
            visited[node] = 1;
            colors[node] = color;
        for(auto it :graph[node]){
            if(!visited[it]){
                if(!dfs(graph,visited,colors,it,!color)){
                    return false;
                }
            }
            else{
                if(colors[it]==color){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n  = graph.size();
        vector<int> visited(n,0);
        vector<int> colors(n,0);
        bool ans = true;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans = ans && dfs(graph,visited,colors,i,0);
            }
        }
        return ans;
    }
};
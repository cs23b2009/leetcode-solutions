class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int> &visited,vector<int> &pathvisited,int node,vector<int> &check){
        visited[node] = 1;
        pathvisited[node] = 1;
        for(auto it:graph[node]){
            if(!visited[it]){
                if(dfs(graph,visited,pathvisited,it,check)){
                    return true;
                }
            }
            else if(pathvisited[it]){
                return true;
            }
        }
        check[node] = 1;
        pathvisited[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,0);
        vector<int> pathvisited(n,0);
        vector<int> check(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(graph,visited,pathvisited,i,check);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
class Solution {
public:
    void bfs(vector<int>& visited,vector<int> adj[],int node){
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            
            for(auto it: adj[ele]){
                if(!visited[it]){
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        int count = 0;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                if(!visited[it]){
                    bfs(visited,adj,it);
                    count++;
                }
            }
        }
        return count;
    }
};
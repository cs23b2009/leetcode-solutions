class Solution {
public:
    void bfs(vector<int>& visited, vector<vector<int>>& adj, int node){
        queue<int> q;
        visited[node] = 1;
        q.push(node);

        while(!q.empty()){
            int ele = q.front();
            q.pop();
            for(auto it : adj[ele]){
                if(!visited[it]){
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> visited(n, 0);
        int count = 0;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                bfs(visited, adj, i);
                count++;
            }
        }
        return count;
    }
};
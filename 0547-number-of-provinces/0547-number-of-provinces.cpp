class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        queue<int> q;
        vector<int> visited(n,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                visited[i] = 1;
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto it:adj[node]){
                        if(!visited[it]){
                            visited[it] = 1;
                            q.push(it);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
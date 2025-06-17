class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack, vector<bool>& safe) {
        visited[node] = true;
        recStack[node] = true;
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, adj, visited, recStack, safe))
                    return true;
            } else if (recStack[neighbor]) {
                return true;
            }
        }

        recStack[node] = false;
        safe[node] = true; // This node leads to no cycle
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> ans;
        vector<bool> visited(n, false);
        vector<bool> recStack(n, false);
        vector<bool> safe(n, false);

        for (int i = 0; i < n; ++i) {
            if (!visited[i])
                dfs(i, adj, visited, recStack, safe);
        }

        for (int i = 0; i < n; ++i) {
            if (safe[i]) ans.push_back(i);
        }

        return ans;
    }
};
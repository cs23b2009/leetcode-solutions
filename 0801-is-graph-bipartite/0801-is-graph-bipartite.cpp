class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int node, int color) {
        visited[node] = color;
        for (int neighbor : graph[node]) {
            if (visited[neighbor] == -1) {
                if (!dfs(graph, visited, neighbor, 1 - color)) {
                    return false;
                }
            } else if (visited[neighbor] == color) {
                return false;  
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, -1); 
        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) {
                if (!dfs(graph, visited, i, 0)) {
                    return false;
                }
            }
        }
        return true;
    }
};
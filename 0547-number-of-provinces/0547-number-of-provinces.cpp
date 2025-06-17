class Solution {
public:
    void dfs(vector<vector<int>>& adjlist, vector<int>& visited, int source) {
        visited[source] = 1;
        for (auto it : adjlist[source]) {
            if (!visited[it]) {
                dfs(adjlist, visited, it);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjlist(n);  // Use vector of vectors for adjacency list

        // Build adjacency list from the isConnected matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjlist[i].push_back(j);
                }
            }
        }

        vector<int> visited(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(adjlist, visited, i);
            }
        }

        return count;
    }
};
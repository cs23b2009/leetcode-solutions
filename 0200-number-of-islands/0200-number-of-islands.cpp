class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || grid[i][j] != '1')
            return;

        visited[i][j] = 1;
        dfs(grid, visited, i + 1, j);
        dfs(grid, visited, i - 1, j);
        dfs(grid, visited, i, j + 1);
        dfs(grid, visited, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        int count = 0;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    ++count;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return count;
    }
};
class Solution {
public:
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    void dfs(vector<vector<int>>& board, vector<vector<int>>& visited, int i, int j, int n, int m) {
        visited[i][j] = 1;
        for (int k = 0; k < 4; ++k) {
            int ni = i + dr[k];
            int nj = j + dc[k];
            if (ni >= 0 && nj >= 0 && ni < n && nj < m &&
                !visited[ni][nj] && board[ni][nj] == 1) {
                dfs(board, visited, ni, nj, n, m);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Boundary DFS for rows
        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 1 && !visited[i][0])
                dfs(board, visited, i, 0, n, m);
            if (board[i][m - 1] == 1 && !visited[i][m - 1])
                dfs(board, visited, i, m - 1, n, m);
        }

        // Boundary DFS for columns
        for (int j = 0; j < m; ++j) {
            if (board[0][j] == 1 && !visited[0][j])
                dfs(board, visited, 0, j, n, m);
            if (board[n - 1][j] == 1 && !visited[n - 1][j])
                dfs(board, visited, n - 1, j, n, m);
        }

        int count = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (board[i][j] == 1 && !visited[i][j])
                    ++count;

        return count;
    }
};
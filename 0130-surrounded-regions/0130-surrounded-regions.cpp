class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j) {
        visited[i][j] = 1;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        for(int k = 0; k < 4; k++) {
            int nrow = i + dr[k];
            int ncol = j + dc[k];
            if(nrow >= 0 && ncol >= 0 && nrow < board.size() && ncol < board[0].size() &&
               visited[nrow][ncol] == 0 && board[nrow][ncol] == 'O') {
                dfs(board, visited, nrow, ncol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0) return;
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            if(!visited[i][0] && board[i][0] == 'O') {
                dfs(board, visited, i, 0);
            }
            if(!visited[i][m - 1] && board[i][m - 1] == 'O') {
                dfs(board, visited, i, m - 1);
            }
        }

        for(int i = 0; i < m; i++) {
            if(!visited[0][i] && board[0][i] == 'O') {
                dfs(board, visited, 0, i);
            }
            if(!visited[n - 1][i] && board[n - 1][i] == 'O') {
                dfs(board, visited, n - 1, i);
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
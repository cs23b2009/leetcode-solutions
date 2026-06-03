class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        vector<int> roww = {-1,0,1,0};
        vector<int> coll = {0,1,0,-1};
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                visited[0][i] = 1;
                q.push({0,i});
            }
            if(board[n-1][i]=='O'){
                visited[n-1][i] = 1;
                q.push({n-1,i});
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                visited[i][0] = 1;
                q.push({i,0});
            }
            if(board[i][m-1]=='O'){
                visited[i][m-1] = 1;
                q.push({i,m-1});
            }
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr = it.first + roww[i];
                int nc = it.second + coll[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    if(board[nr][nc]=='O' && !visited[nr][nc]){
                        visited[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && board[i][j] =='O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
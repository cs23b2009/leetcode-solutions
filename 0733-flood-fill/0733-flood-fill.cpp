class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int original = image[sr][sc];
        image[sr][sc] = color;
        vector<int> roww = {-1,0,1,0};
        vector<int> coll = {0,1,0,-1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr = it.first + roww[i];
                int nc = it.second + coll[i];
                if(nr>=0 && nr <n && nc>=0 && nc<m){
                    if(image[nr][nc]!=color && image[nr][nc]==original){
                        image[nr][nc] = color;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return image;
    }
};
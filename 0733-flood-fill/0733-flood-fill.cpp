class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int originalColor) {
        if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size())
            return;
        if(image[sr][sc] != originalColor || image[sr][sc] == color)
            return;

        image[sr][sc] = color;

        dfs(image, sr - 1, sc, color, originalColor); // up
        dfs(image, sr + 1, sc, color, originalColor); // down
        dfs(image, sr, sc - 1, color, originalColor); // left
        dfs(image, sr, sc + 1, color, originalColor); // right
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if(originalColor != color) {
            dfs(image, sr, sc, color, originalColor);
        }
        return image;
    }
};
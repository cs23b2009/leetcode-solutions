class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dp(n, vector<int>(n, 1e8));
        
        for(int i = 0; i < n; i++)
            dp[i][i] = 0;

        // Update distances for edges (undirected)
        for(auto& e : edges){
            int u = e[0], v = e[1], w = e[2];
            dp[u][v] = w;
            dp[v][u] = w;
        }

        // Floyd-Warshall to calculate all pairs shortest paths
        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

        int ans = n, index = -1;
        for(int i = 0; i < n; ++i) {
            int cnt = 0;
            for(int j = 0; j < n; ++j)
                if(i != j && dp[i][j] <= distanceThreshold)
                    ++cnt;

            if(cnt <= ans){
                ans = cnt;
                index = i;
            }
        }

        return index;
    }
};
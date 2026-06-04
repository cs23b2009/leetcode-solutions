class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        dist[0][0] = 0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            auto [effort,pos] = pq.top();
            auto [r,c] = pos;
            pq.pop();

            if(r == n-1 && c == m-1) return effort;

            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int newEffort = max(effort,
                        abs(heights[nr][nc]-heights[r][c]));

                    if(newEffort < dist[nr][nc]){
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> distance(n, vector<int>(m, 1e9));
        distance[0][0] = 0;

        priority_queue< pair<int, pair<int,int>>, vector< pair<int, pair<int,int>> >, greater< pair<int, pair<int,int>> > > pq;
        pq.push({0, {0, 0}});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto [diff, pos] = pq.top();
            auto [row, col] = pos;
            pq.pop();

            if (row == n - 1 && col == m - 1) return diff;

            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
                    int effort = max(diff, abs(heights[nrow][ncol] - heights[row][col]));
                    if (effort < distance[nrow][ncol]) {
                        distance[nrow][ncol] = effort;
                        pq.push({effort, {nrow, ncol}});
                    }
                }
            }
        }

        return 0;
    }
};
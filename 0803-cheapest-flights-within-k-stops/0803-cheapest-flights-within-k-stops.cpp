class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& flight : flights) {
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        }

        queue<tuple<int, int, int>> q;
        q.push({src, 0, 0});
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while (!q.empty()) {
            auto [u, cost, stops] = q.front();
            q.pop();

            if (stops > k) continue;

            for (auto& [v, wt] : adj[u]) {
                if (cost + wt < dist[v]) {
                    dist[v] = cost + wt;
                    q.push({v, dist[v], stops + 1});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
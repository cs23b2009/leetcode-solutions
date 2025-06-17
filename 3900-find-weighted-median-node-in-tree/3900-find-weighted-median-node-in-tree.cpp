#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int LOG = 17; 
    
    vector<vector<pair<int,int>>> tree;
    
    vector<vector<int>> up;
    
    vector<int> depth;
    
    vector<long long> distToRoot;
    
    vector<vector<long long>> distUp;

    void dfs(int u, int p, int w) {
        up[u][0] = p;
        distUp[u][0] = w;
        for (auto [v, wt] : tree[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            distToRoot[v] = distToRoot[u] + wt;
            dfs(v, u, wt);
        }
    }

    void preprocess(int n) {
        for (int k = 1; k < LOG; ++k) {
            for (int i = 0; i < n; ++i) {
                int mid = up[i][k-1];
                if (mid != -1) {
                    up[i][k] = up[mid][k-1];
                    distUp[i][k] = distUp[i][k-1] + distUp[mid][k-1];
                }
            }
        }
    }

    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        for (int k = LOG - 1; k >= 0; --k) {
            if (up[u][k] != -1 && depth[up[u][k]] >= depth[v]) {
                u = up[u][k];
            }
        }

        if (u == v) return u;

        for (int k = LOG - 1; k >= 0; --k) {
            if (up[u][k] != -1 && up[v][k] != -1 && up[u][k] != up[v][k]) {
                u = up[u][k];
                v = up[v][k];
            }
        }
        return up[u][0];
    }

    vector<int> findMedian(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<int>> sabrelonta = edges;

        tree.assign(n, {});
        up.assign(n, vector<int>(LOG, -1));
        distUp.assign(n, vector<long long>(LOG, 0));
        depth.assign(n, 0);
        distToRoot.assign(n, 0);

        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            tree[u].push_back({v, w});
            tree[v].push_back({u, w});
        }

        dfs(0, -1, 0); 
        preprocess(n);

        vector<int> res;

        for (auto& q : queries) {
            int u_query = q[0], v_query = q[1];

            if (u_query == v_query) { 
                res.push_back(u_query);
                continue;
            }

            int lca_node = getLCA(u_query, v_query);
            
            long long total_path_weight = distToRoot[u_query] + distToRoot[v_query] - 2 * distToRoot[lca_node];
            
            long long half_weight_ceiling = (total_path_weight + 1) / 2;

            int median_node = -1;

            long long path_u_query_to_lca_weight = distToRoot[u_query] - distToRoot[lca_node];

            if (path_u_query_to_lca_weight >= half_weight_ceiling) {
                int current_search_node = u_query;
                for (int k = LOG - 1; k >= 0; --k) {
                    int ancestor = up[current_search_node][k];
                    if (ancestor != -1 && depth[ancestor] >= depth[lca_node] &&
                        (distToRoot[u_query] - distToRoot[ancestor]) < half_weight_ceiling) {
                        current_search_node = ancestor;
                    }
                }
                median_node = up[current_search_node][0];
            } else {
                long long remaining_target_weight_from_lca = half_weight_ceiling - path_u_query_to_lca_weight;

                int current_search_node = v_query;
                for (int k = LOG - 1; k >= 0; --k) {
                    int ancestor = up[current_search_node][k];
                    if (ancestor != -1 && depth[ancestor] >= depth[lca_node] &&
                        (distToRoot[ancestor] - distToRoot[lca_node]) >= remaining_target_weight_from_lca) {
                        current_search_node = ancestor;
                    }
                }
                median_node = current_search_node;
            }
            res.push_back(median_node);
        }
        return res;
    }
};

class DisjointSet {
    vector<int> parent, rank, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int parentnode(int node) {
        if (node == parent[node]) return node;
        return parent[node] = parentnode(parent[node]);  // Path compression
    }

    void combineunionsize(int u, int v) {
        int parentu = parentnode(u);
        int parentv = parentnode(v);
        if (parentu == parentv) return;

        if (size[parentu] < size[parentv]) {
            parent[parentu] = parentv;
            size[parentv] += size[parentu];
        } else {
            parent[parentv] = parentu;
            size[parentu] += size[parentv];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxVal = 0;
        for (auto& stone : stones) {
            maxVal = max(maxVal, max(stone[0], stone[1]));
        }

        DisjointSet ds(20002);  // Because max x and y can be 10^4

        unordered_set<int> unique_nodes;

        for (auto& stone : stones) {
            int row = stone[0];
            int col = stone[1] + 10001;  // Offset to avoid collision
            ds.combineunionsize(row, col);

            unique_nodes.insert(row);
            unique_nodes.insert(col);
        }

        int components = 0;
        for (int node : unique_nodes) {
            if (ds.parentnode(node) == node) {
                components++;
            }
        }

        return stones.size() - components;
    }
};
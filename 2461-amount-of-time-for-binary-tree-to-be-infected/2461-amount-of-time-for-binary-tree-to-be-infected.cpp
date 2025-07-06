class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* target = nullptr;

        // Combine parent mapping and target locating
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node->val == start) {
                target = node;
            }
            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        // BFS from target to calculate infection time
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        int time = -1;

        while (!q.empty()) {
            int size = q.size();
            time++;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();
                if (node->left && visited.find(node->left) == visited.end()) {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if (node->right && visited.find(node->right) == visited.end()) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if (parent.count(node) && visited.find(parent[node]) == visited.end()) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
        }

        return time;
    }
};
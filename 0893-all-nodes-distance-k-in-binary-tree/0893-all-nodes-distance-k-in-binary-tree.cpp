class Solution {
public:
    void par(unordered_map<TreeNode*,TreeNode*> &parentele ,TreeNode* root ){
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();
            if(node->left) {
                parentele[node->left] = node;
                que.push(node->left);
            }
            if(node->right) {
                parentele[node->right] = node;
                que.push(node->right);
            }
        }
    } 

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentele;
        par(parentele, root);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> que;
        que.push(target);
        visited[target] = true;
        
        int currlevel = 0;
        while(!que.empty()) {
            int size = que.size();
            if(currlevel++ == k) break;

            for(int i = 0; i < size; ++i) {
                TreeNode* node = que.front(); que.pop();

                if(node->left && !visited[node->left]) {
                    visited[node->left] = true;
                    que.push(node->left);
                }
                if(node->right && !visited[node->right]) {
                    visited[node->right] = true;
                    que.push(node->right);
                }
                if(parentele[node] && !visited[parentele[node]]) {
                    visited[parentele[node]] = true;
                    que.push(parentele[node]);
                }
            }
        }

        vector<int> ans;
        while(!que.empty()) {
            ans.push_back(que.front()->val);
            que.pop();
        }

        return ans;
    }
};
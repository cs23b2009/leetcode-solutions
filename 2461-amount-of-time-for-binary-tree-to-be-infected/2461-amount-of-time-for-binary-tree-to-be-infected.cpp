/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parentele;
        par(parentele, root);
        TreeNode* target = nullptr;
        queue<TreeNode*> que1;
        que1.push(root);
        while(!que1.empty()){
            TreeNode* node = que1.front();
            que1.pop();
            if(node->val==start) {
                target = node;
                break;
            }
            if(node->left) {
                que1.push(node->left);
            }
            if(node->right) {
                que1.push(node->right);
            }
        }
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> que;
        que.push(target);
        visited[target] = true;
        
        int currlevel = 0;
        while(!que.empty()) {
            int size = que.size();
            currlevel++;

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

       return currlevel-1;
    }

     
};


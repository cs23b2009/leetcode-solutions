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
   vector<vector<int>> ans(TreeNode* root){
    if(root==nullptr) return {};
    vector<vector<int>> store;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        vector<int> roww;
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode* node = q.front();
            q.pop();
            roww.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        store.push_back(roww);
    }
    for(int i=1;i<store.size();i+=2){
        reverse(store[i].begin(),store[i].end());
    }
    return store;
   }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return ans(root);
    }
};
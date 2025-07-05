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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = 0;
        queue<pair<TreeNode*, long long>> que;
        que.push({root, 0});
        
        while(!que.empty()) {
            int size = que.size();
            long long minind = que.front().second; // to prevent overflow
            long long firstnode = 0, lastnode = 0;
            
            for(int i = 0; i < size; i++) {
                long long curr = que.front().second - minind;
                TreeNode* node = que.front().first;
                que.pop();

                if(i == 0) firstnode = curr;
                if(i == size - 1) lastnode = curr;

                if(node->left) {
                    que.push({node->left, curr * 2 + 1});
                }
                if(node->right) {
                    que.push({node->right, curr * 2 + 2});
                }
            }
            ans = max(ans, (int)(lastnode - firstnode + 1));
        }
        return ans;
    }
};
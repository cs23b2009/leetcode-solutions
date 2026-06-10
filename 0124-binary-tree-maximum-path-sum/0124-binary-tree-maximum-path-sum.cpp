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
    int ans = INT_MIN;

    int weight(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = max(0, weight(root->left));
        int right = max(0, weight(root->right));
        ans = max(ans, root->val + left + right);
        return root->val + max(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        weight(root);
        return ans;
    }
};
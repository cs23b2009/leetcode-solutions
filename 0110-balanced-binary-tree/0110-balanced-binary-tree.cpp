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
    // Helper function returns the height of the tree if balanced, else -1
    int check(TreeNode* root) {
        if (!root) return 0;

        int left = check(root->left);
        if (left == -1) return -1; // Left subtree is not balanced

        int right = check(root->right);
        if (right == -1) return -1; // Right subtree is not balanced

        if (abs(left - right) > 1) return -1; // Current node is not balanced

        return 1 + max(left, right); // Return height if balanced
    }

    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};
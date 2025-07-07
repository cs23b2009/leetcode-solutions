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
    int maxSum = INT_MIN;

    int maxGain(TreeNode* root) {
        if (!root) return 0;

        // Recursively get max gain from left and right, ignore negative paths
        int left = max(0, maxGain(root->left));
        int right = max(0, maxGain(root->right));

        // Max path including this node as the highest node
        int currentMax = root->val + left + right;

        // Update global max if needed
        maxSum = max(maxSum, currentMax);

        // Return max gain to parent (only one side can be included in parent path)
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};
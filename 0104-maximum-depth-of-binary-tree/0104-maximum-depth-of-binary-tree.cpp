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
    int ans(TreeNode* head){
        if(head==nullptr) return 0;
        int leftmax = 0;
        int rightmax = 0;
        if(head->left) leftmax = ans(head->left);
        if(head->right) rightmax = ans(head->right);
        return max(leftmax,rightmax) + 1;
    }
    int maxDepth(TreeNode* root) {
        return ans(root);
    }
};
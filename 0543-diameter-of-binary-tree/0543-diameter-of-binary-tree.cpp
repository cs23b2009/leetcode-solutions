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
    int diameter = 0;
    int height(TreeNode* head){
        if(head==nullptr) return 0 ;
        int leftmax = height(head->left);
        int rightmax = height(head->right);
        diameter = max(diameter,leftmax+rightmax);
        return 1 + max(leftmax,rightmax);
    }
    int diameterOfBinaryTree(TreeNode* root) {
      height(root);  
      return diameter;
    }
};
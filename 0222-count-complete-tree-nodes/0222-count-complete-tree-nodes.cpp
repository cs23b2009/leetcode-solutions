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
    int heightlh(TreeNode* root){
        int height = 0;
        while(root){
            height++;
            root = root->left;
        }
        return height;
    }
    int heightrh(TreeNode* root){
        int height = 0;
        while(root){
            height++;
            root = root->right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = heightlh(root);
        int rh = heightrh(root);
        if(lh==rh) return (1<<lh) -1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
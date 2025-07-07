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
    TreeNode* rightchild(TreeNode* root){
        if(root->right==nullptr){
            return root;
        }
        return rightchild(root->right);
    }
    TreeNode* helper(TreeNode* root){
        if(!root->left) return root->right;
        if(!root->right) return root->left;
        TreeNode* Rightchild = root->right;
        TreeNode* extremeleft = rightchild(root->left);
        extremeleft->right = Rightchild;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return root;
        if(root->val==key) return helper(root);
        TreeNode* dummy = root;
        while(dummy!=nullptr){
            if(key>dummy->val){
                if(dummy->right!=nullptr && dummy->right->val==key){
                    dummy->right = helper(dummy->right);
                    break;
                }
                else{
                    dummy = dummy->right;
                }
            }
            else{
                if(dummy->left!=nullptr && dummy->left->val == key){
                    dummy->left = helper(dummy->left);
                    break;
                }
                else{
                    dummy = dummy->left;
                }
            }
        }
        return root;
    }
};
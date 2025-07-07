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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* mover = root;
        while(mover!=nullptr){
            if(mover->left==nullptr){
                ans.push_back(mover->val);
                mover = mover->right;
            }
            else{
                TreeNode* start = mover ;
                TreeNode* lastnode = mover->left;
                mover = lastnode->right;
                while(mover!=nullptr && mover!=start){
                    lastnode = mover;
                    mover = lastnode->right;
                }
                if(mover==start){
                    lastnode->right = nullptr;
                    ans.push_back(mover->val);
                    mover = mover->right;
                }
                else{
                    lastnode->right = start;
                    mover = start->left;
                }
            }
        }
        return ans;
    }
}; 
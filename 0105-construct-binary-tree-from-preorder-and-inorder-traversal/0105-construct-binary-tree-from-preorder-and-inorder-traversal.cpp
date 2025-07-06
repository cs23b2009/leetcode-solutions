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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }
        return buildtree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderIndex);
    }

private:
    TreeNode* buildtree(vector<int>& preorder, int prestart, int preend,
                        vector<int>& inorder, int instart, int inend,
                        unordered_map<int, int>& inorderIndex) {
        
        if (prestart > preend || instart > inend)
            return nullptr;

        int rootVal = preorder[prestart];
        TreeNode* root = new TreeNode(rootVal);

        int rootIndexInInorder = inorderIndex[rootVal];
        int leftTreeSize = rootIndexInInorder - instart;

        root->left = buildtree(preorder, prestart + 1, prestart + leftTreeSize,
                               inorder, instart, rootIndexInInorder - 1, inorderIndex);
        
        root->right = buildtree(preorder, prestart + leftTreeSize + 1, preend,
                                inorder, rootIndexInInorder + 1, inend, inorderIndex);
        
        return root;
    }
};
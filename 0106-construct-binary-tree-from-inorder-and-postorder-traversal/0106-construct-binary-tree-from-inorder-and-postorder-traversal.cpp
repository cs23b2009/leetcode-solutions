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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        int postIndex = postorder.size() - 1;
        return build(postorder, inorder, 0, inorder.size() - 1, postIndex, inorderIndex);
    }

private:
    TreeNode* build(vector<int>& postorder, vector<int>& inorder, int inStart, int inEnd, 
                    int& postIndex, unordered_map<int, int>& inorderIndex) {

        if (inStart > inEnd || postIndex < 0)
            return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int inRootIndex = inorderIndex[rootVal];

        // Build right subtree first, because we are consuming postorder from the end
        root->right = build(postorder, inorder, inRootIndex + 1, inEnd, postIndex, inorderIndex);
        root->left = build(postorder, inorder, inStart, inRootIndex - 1, postIndex, inorderIndex);

        return root;
    }
};
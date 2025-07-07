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
class BSTIterator
{
public:
    stack<TreeNode*>inorder;
    bool reverse=false;

    BSTIterator(TreeNode* root,bool rev)
    {
        reverse=rev;
        pushAll(root);
    }

    void pushAll(TreeNode* node)
    {
        while(node)
        {
            inorder.push(node);
            if(reverse)
                node=node->right;
            else
                node=node->left;
        }
    }
    
    int next()
    {
        TreeNode* node=inorder.top();
        inorder.pop();
        if(reverse)
            pushAll(node->left);
        else
            pushAll(node->right);
        return node->val;
    }
};

class Solution
{
public:
    bool findTarget(TreeNode* root,int k)
    {
        BSTIterator itr1(root,false);
        BSTIterator itr2(root,true);
        int left=itr1.next(),right=itr2.next();
        while(left<right)
        {
            int sum=left+right;
            if(sum==k)
                return true;
            else if(sum<k)
                left=itr1.next();
            else
                right=itr2.next();
        }
        return false;
    }
};
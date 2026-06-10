class Solution {
public:
    int ans(TreeNode* head){
        if(head == nullptr) return 0;

        int leftmax = ans(head->left);
        if(leftmax == -1) return -1;

        int rightmax = ans(head->right);
        if(rightmax == -1) return -1;

        if(abs(leftmax - rightmax) > 1) return -1;

        return 1 + max(leftmax, rightmax);
    }

    bool isBalanced(TreeNode* root) {
        return ans(root) != -1;
    }
};
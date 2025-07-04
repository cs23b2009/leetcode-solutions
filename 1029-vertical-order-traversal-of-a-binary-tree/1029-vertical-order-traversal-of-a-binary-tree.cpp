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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> result;

        if(root==NULL) return result;

        map<int,map<int,multiset<int>>> mp; // we use a multiset at each coordinate (x,y) since 2 nodes can exist on the same position + there can be duplicate values
        queue<pair<TreeNode*,pair<int,int>>> q;

        q.push({root,{0,0}});

        while(!q.empty()){

            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int x = it.second.first;
            int y = it.second.second;

            mp[x][y].insert(node->val);

            if(node->left){
                q.push({node->left,{x-1,y+1}});  //if its a left node decrement the x axis value
            }
            if(node->right){
                q.push({node->right,{x+1,y+1}});
            }
        }

        for(auto it : mp){   //traverses each vertical index

            vector<int> col;

            for(auto q : it.second){   //traverses each horizontal index

                for(auto i : q.second){ //traverse the multiset at this(x,y) coordinate {there can be multiple}
                    col.push_back(i);
                }
            }

            result.push_back(col);
        }

        return result;
    }
};
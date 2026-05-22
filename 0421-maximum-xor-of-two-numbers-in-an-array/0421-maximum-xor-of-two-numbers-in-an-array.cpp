struct Node{
    Node* next[2];

    Node(){
        next[0]=NULL;
        next[1]=NULL;
    }
};

class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }

    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)& 1;
            if(node->next[bit]==NULL){
                node->next[bit]=new Node();
            }
            node=node->next[bit];
        }
    }

    int getmax (int num){
        Node* cur=root;
        int maxi=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            if(cur->next[1-bit]!=NULL){
                maxi=maxi | (1<<i);
                cur=cur->next[1-bit];
            }
            else{
                cur=cur->next[bit];
            }

        }

        return maxi;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxi=-1e9;
        Trie t;
        for(auto it:nums){
            t.insert(it);
        }
        for(int i=0;i<(int)nums.size();i++){
            
           maxi=max(maxi,t.getmax(nums[i]));
        }

        return maxi;
    }
};
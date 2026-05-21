class Solution {
public:
    int maxDepth(string s) {
        int balance = 0;
        int ans = INT_MIN;
        for(auto it:s){
            ans = max(ans,balance);
            if(it=='('){
                balance++;
                continue;
            }
            if(it==')'){
                balance--;
                continue;
            }    
        }
        return ans;
    }
};
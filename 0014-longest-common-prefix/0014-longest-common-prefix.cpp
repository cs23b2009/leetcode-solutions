class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int len = INT_MAX;

        for(int i = 0; i < strs.size(); i++){
            len = min(len, (int)strs[i].length());
        }

        for(int i = 0; i < len; i++){
            char ch = strs[0][i];

            for(int j = 0; j < strs.size(); j++){
                if(ch != strs[j][i]){
                    return ans;
                }
            }
            ans += ch;
        }

        return ans;
    }
};
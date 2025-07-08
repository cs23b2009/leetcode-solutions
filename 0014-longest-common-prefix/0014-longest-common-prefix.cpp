class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()) return "";
        string prefix = "";
        int j=0;
        while(j<strs[0].size()){
            for(int i=0;i<strs.size();i++){
                if(strs[i][j]!=strs[0][j]){
                    return prefix;
                }
            }
            prefix += strs[0][j++];
        }
        return prefix;
    }
};
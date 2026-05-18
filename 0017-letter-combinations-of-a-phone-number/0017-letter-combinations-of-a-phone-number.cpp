class Solution {
public:
    void recur(int index,string digits,vector<string>& ans,string& helping,vector<string>mapping){
        if(index==digits.length()){
            ans.push_back(helping);
            return;
        }
        string charr = mapping[digits[index]-'0'];
        for(int i=0;i<charr.length();i++){
            helping.push_back(charr[i]);
            recur(index+1,digits,ans,helping,mapping);
            helping.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return {};
        }
        vector<string> mapping = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"

        };
       vector<string> ans;
       string helping;
       recur(0,digits,ans,helping,mapping);
       return ans; 
    }
};
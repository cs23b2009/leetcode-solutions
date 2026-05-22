class Solution {
public:
    int numberOfSubstrings(string s) {
       int ans = 0;
       int left = 0;
       unordered_map<char,int>mpp;
       for(int right=0;right<s.size();right++){
        mpp[s[right]]++;
        while(mpp.size()==3){
            ans += s.size() - right;
                mpp[s[left]]--;
                if(mpp[s[left]]==0){
                    mpp.erase(s[left]);
                }
                left++;
        }
       }
       return ans; 
    }
};
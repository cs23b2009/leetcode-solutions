class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()>=0 && s.length()<=1) return s.length();
        unordered_map<char,int> mpp;
        int l = 0 ;
        int r = 0 ;
        int maxlen = 0;
        while(r<s.length()){
            if(mpp.find(s[r])!=mpp.end()){
                l = max(mpp[s[r]] + 1, l);
            }
            mpp[s[r]] = r ;
            maxlen = max(maxlen,r-l+1);
               r++;
        }
        return maxlen;
    }
};
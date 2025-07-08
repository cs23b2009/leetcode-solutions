class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;
        int l = 0, maxlen = 0;
        
        for(int r = 0; r < s.length(); r++) {
            if(mpp.find(s[r]) != mpp.end()) {
                // Move left only forward
                l = max(mpp[s[r]] + 1, l);
            }
            mpp[s[r]] = r;
            maxlen = max(maxlen, r - l + 1);
        }
        
        return maxlen;
    }
};
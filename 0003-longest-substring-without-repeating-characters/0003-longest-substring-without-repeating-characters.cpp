class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int len = 0;
        int left = 0;
        vector<int> freq(256, 0);
        for(int right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            while(freq[s[right]] > 1) {
                freq[s[left]]--;
                left++;
            }
            len = max(len, right - left + 1);
        }
        return len;
    }
};
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) return "";

        unordered_map<char, int> tFreq;
        for (char ch : t) tFreq[ch]++;

        int required = tFreq.size(); 
        int formed = 0;
        unordered_map<char, int> windowFreq;

        int l = 0, r = 0;
        int minLen = INT_MAX, startIdx = 0;

        while (r < s.size()) {
            char c = s[r];
            windowFreq[c]++;

            if (tFreq.count(c) && windowFreq[c] == tFreq[c]) {
                formed++;
            }

            while (l <= r && formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIdx = l;
                }

                windowFreq[s[l]]--;
                if (tFreq.count(s[l]) && windowFreq[s[l]] < tFreq[s[l]]) {
                    formed--;
                }
                l++;
            }

            r++;
        }

        return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
    }
};
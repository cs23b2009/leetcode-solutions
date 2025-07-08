class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        vector<int> freq(26, 0);
        for (char c : s1) freq[c - 'a']++;

        for (int i = 0; i <= s2.length() - s1.length(); i++) {
            vector<int> freq1(26, 0);
            string temp = s2.substr(i, s1.length());
            for (char c : temp) freq1[c - 'a']++;
            if (freq == freq1) return true;
        }

        return false;
    }
};
class Solution {
public:
    string expand(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        if (s.empty()) return "";
        string ans = "";

        for (int i = 0; i < s.length(); i++) {
            string odd = expand(s, i, i);
            if (odd.length() > ans.length()) ans = odd;
            string even = expand(s, i, i + 1);
            if (even.length() > ans.length()) ans = even;
        }

        return ans;
    }
};
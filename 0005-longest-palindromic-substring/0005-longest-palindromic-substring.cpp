class Solution {
public:
    bool palindromee(string &s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int len = 0;
        string ans = "";

        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) {

                if(palindromee(s, i, j)) {

                    if(len < j - i + 1) {
                        len = j - i + 1;
                        ans = s.substr(i, j - i + 1);
                    }
                }
            }
        }

        return ans;
    }
};
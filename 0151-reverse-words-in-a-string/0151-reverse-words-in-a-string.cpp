class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        string ans = "";
        int start = 0;

        for (int i = 0; i <= s.length(); i++) {

            if (i == s.length() || s[i] == ' ') {

                string word = s.substr(start, i - start);

                reverse(word.begin(), word.end());

                if(word.length() > 0){
                    if(ans.length() > 0){
                        ans += ' ';
                    }
                    ans += word;
                }

                start = i + 1;
            }
        }

        return ans;
    }
};
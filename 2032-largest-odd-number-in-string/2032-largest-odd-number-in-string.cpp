class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.size() - 1; i >= 0; i--) {
            char ch = num[i];
            if ((ch - '0') % 2 == 1) { // check if odd
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};
class Solution {
public:
    int longestPalindromeSubseq(string text1) {
        string text2 = text1;
        reverse(text2.begin(),text2.end());
        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            vector<int> curr(m + 1, 0);
            for (int j = m - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    curr[j] = 1 + prev[j + 1];
                } else {
                    curr[j] = max(prev[j], curr[j + 1]);
                }
            }
            prev = curr;
        }
        return prev[0];
    }
};
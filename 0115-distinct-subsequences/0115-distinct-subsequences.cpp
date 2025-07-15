class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> prev(m + 1, 0);
        prev[0] = 1;

        for (int i = 1; i <= n; i++) {
            vector<int> curr(m + 1, 0);
            curr[0] = 1;
            for (int j = 1; j <= m; j++) {
                long long val = prev[j];
                if (s[i - 1] == t[j - 1]) {
                    val += prev[j - 1];
                    curr[j] = val;
                } else {
                    curr[j] = val;
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};
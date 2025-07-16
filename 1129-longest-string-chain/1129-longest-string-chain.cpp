class Solution {
public:
    // Check if 'two' can be formed by adding one character to 'one'
    bool compare(string &one, string &two) {
        if (two.size() != one.size() + 1) return false;

        int i = 0, j = 0;
        bool skipped = false;

        while (i < one.size() && j < two.size()) {
            if (one[i] == two[j]) {
                i++; j++;
            } else {
                if (skipped) return false;
                skipped = true;
                j++;
            }
        }

        return true;
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.size() < b.size(); // Sort by length
        });

        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;

        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (compare(words[prev], words[i]) && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};
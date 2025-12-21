class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<int> ok(n - 1, 0);
        int res = 0;

        for (int j = 0; j < m; j++) {
            bool bad = false;
            for (int i = 0; i < n - 1; i++) {
                if (!ok[i] && strs[i][j] > strs[i + 1][j]) {
                    bad = true;
                    break;
                }
            }
            if (bad) {
                res++;
            } else {
                for (int i = 0; i < n - 1; i++) {
                    if (strs[i][j] < strs[i + 1][j]) {
                        ok[i] = 1;
                    }
                }
            }
        }
        return res;
    }
};
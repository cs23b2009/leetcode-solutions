class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> preN(n + 1, 0), sufY(n + 1, 0);

        for (int i = 0; i < n; i++) {
            preN[i + 1] = preN[i] + (customers[i] == 'N');
        }

        for (int i = n - 1; i >= 0; i--) {
            sufY[i] = sufY[i + 1] + (customers[i] == 'Y');
        }

        int ans = 0;
        int mini = preN[0] + sufY[0];

        for (int i = 1; i <= n; i++) {
            int cur = preN[i] + sufY[i];
            if (cur < mini) {
                mini = cur;
                ans = i;
            }
        }

        return ans;
    }
};
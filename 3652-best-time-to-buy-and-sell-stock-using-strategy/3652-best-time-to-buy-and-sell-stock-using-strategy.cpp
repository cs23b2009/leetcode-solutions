#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        int half = k / 2;

        long long base = 0;
        for (int i = 0; i < n; i++) {
            base += 1LL * prices[i] * strategy[i];
        }

        vector<long long> leftGain(n), rightGain(n);
        for (int i = 0; i < n; i++) {
            long long old = 1LL * prices[i] * strategy[i];
            leftGain[i] = -old;
            rightGain[i] = prices[i] - old;
        }

        long long currGain = 0;
        for (int i = 0; i < half; i++)
            currGain += leftGain[i];
        for (int i = half; i < k; i++)
            currGain += rightGain[i];

        long long maxGain = currGain;

        for (int i = k; i < n; i++) {
            currGain -= leftGain[i - k];
            currGain -= rightGain[i - half];
            currGain += leftGain[i - half];
            currGain += rightGain[i];
            maxGain = max(maxGain, currGain);
        }

        return base + max(0LL, maxGain);
    }
};
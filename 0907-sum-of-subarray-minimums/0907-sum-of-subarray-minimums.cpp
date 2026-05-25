class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> nse(n), pse(n);
        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (st.empty())
                pse[i] = i + 1;
            else
                pse[i] = i - st.top();

            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty())
                nse[i] = n - i;
            else
                nse[i] = st.top() - i;

            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long contrib =
                (1LL * arr[i] * pse[i] * nse[i]) % MOD;

            ans = (ans + contrib) % MOD;
        }

        return ans;
    }
};
class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
         int n = arr.size();
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
                (1LL * arr[i] * pse[i] * nse[i]);

            ans = (ans + contrib) ;
        }
        vector<int> nge(n), pge(n);
        stack<int> st1;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st1.empty() && arr[st1.top()] < arr[i]) {
                st1.pop();
            }

            if (st1.empty())
                pge[i] = i + 1;
            else
                pge[i] = i - st1.top();

            st1.push(i);
        }

        while (!st1.empty()) st1.pop();

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st1.empty() && arr[st1.top()] <= arr[i]) {
                st1.pop();
            }

            if (st1.empty())
                nge[i] = n - i;
            else
                nge[i] = st1.top() - i;

            st1.push(i);
        }

        long long ans1 = 0;

        for (int i = 0; i < n; i++) {
            long long contrib =
                (1LL * arr[i] * pge[i] * nge[i]);

            ans1 = (ans1 + contrib) ;
        }
        return ans1-ans;

    }
};
class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> pse(n), nse(n);

        stack<int> st;

        // PSE
        for (int i = 0; i < n; i++) {

            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        while (!st.empty()) st.pop();

        // NSE
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        int maxi = 0;

        for (int i = 0; i < n; i++) {

            int width = nse[i] - pse[i] - 1;

            maxi = max(maxi, heights[i] * width);
        }

        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> heights(m, 0);

        int maxi = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                }
                else {
                    heights[j] = 0;
                }
            }

            maxi = max(maxi, largestRectangleArea(heights));
        }

        return maxi;
    }
};
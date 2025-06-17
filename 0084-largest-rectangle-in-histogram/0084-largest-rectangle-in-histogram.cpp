class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n);
        vector<int> pse(n);
        stack<int> st;

        // Compute NSE (Next Smaller Element)
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Clear the stack before reusing
        while(!st.empty()) st.pop();

        // Compute PSE (Previous Smaller Element)
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Calculate max area
        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            int area = width * heights[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
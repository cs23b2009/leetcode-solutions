class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m,0);
        int j = n-1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
        int n = heights.size();
        vector<int> nse(n);
        vector<int> pse(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            int area = width * heights[i];
            maxArea = max(maxArea, area);
        }

        ans= max(ans, maxArea );
            

        }
         return ans;
    }
   

};
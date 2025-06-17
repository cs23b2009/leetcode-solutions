class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int asteroid : asteroids) {
            if (st.empty() || asteroid > 0) {
                st.push(asteroid);
                continue;
            }
            int flag = 1;
            while (!st.empty() && st.top() > 0 && flag != -1) {
                if (st.top() < abs(asteroid)) {
                    st.pop();
                } else if (st.top() > abs(asteroid)) {
                    flag = -1;
                } else if (st.top() == abs(asteroid)) {
                    flag = -1;
                    st.pop();
                }
            }
            if(flag!=-1) st.push(asteroid);
        }
        int n = st.size();
        vector<int> ans(n, 0);
        int i = n - 1;
        while (!st.empty()) {
            ans[i--] = st.top();
            st.pop();
        }
        return ans;
    }
};
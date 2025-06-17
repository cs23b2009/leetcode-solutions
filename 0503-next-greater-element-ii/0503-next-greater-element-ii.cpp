class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size());
        stack<int> st;
        int n = nums.size();
        for (int i = 2*nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums[i%n] >= st.top()) {
                st.pop();
            }
            if(i<n){ 
            if (st.empty()) {
                ans[i] = -1;
            } else {
                
                ans[i] = st.top();
            }
            }
            st.push(nums[i%n]);
        }
        return ans;
    }
};
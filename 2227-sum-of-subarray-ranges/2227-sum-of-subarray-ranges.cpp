class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int length = nums.size();
        vector<int> left(length, -1);
        vector<int> right(length, length);
        stack<int> stk;

        for (int i = 0; i < length; ++i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }

        stk = stack<int>();

        for (int i = length - 1; i >= 0; --i) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        stk = stack<int>();
        long long sum1 = 0;
        for (int i = 0; i < length; ++i) {
            sum1 += static_cast<long long>(i - left[i]) * (right[i] - i) * nums[i] ;
        }

        vector<int> left1(length, -1);
        vector<int> right1(length, length);

        for (int i = 0; i < length; ++i) {
            while (!stk.empty() && nums[stk.top()] < nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                left1[i] = stk.top();
            }
            stk.push(i);
        }

        stk = stack<int>();

        for (int i = length - 1; i >= 0; --i) {
            while (!stk.empty() && nums[stk.top()] <= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right1[i] = stk.top();
            }
            stk.push(i);
        }
        long long sum2 = 0;
        for (int i = 0; i < length; ++i) {
            sum2 += static_cast<long long>(i - left1[i]) * (right1[i] - i) * nums[i] ;
        }
        return sum2-sum1;
    }
};
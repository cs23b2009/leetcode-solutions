class Solution {
public:
 
    int satisfy(vector<int>& nums, int mid) {
        int sum = 0;
        int cnt = 1;

        for (int x : nums) {
            if (sum + x <= mid) {
                sum += x;
            } else {
                cnt++;
                sum = x;  
            }
        }
        return cnt;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = 0, high = 0;

        
        for (int x : nums) {
            low = max(low, x);
            high += x;    
        }

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (satisfy(nums, mid) <= k) {
                ans = mid;
                high = mid - 1; 
            } else {
                low = mid + 1; 
            }
        }
        return ans;
    }
};
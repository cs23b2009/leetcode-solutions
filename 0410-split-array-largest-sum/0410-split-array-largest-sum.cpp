class Solution {
public:
    int arra(vector<int>& arr, int mid){
        int count = 0;
        int ans = 1;

        for(int i=0;i<arr.size();i++){
            if(count + arr[i] > mid){
                ans++;
                count = arr[i];
            }
            else{
                count += arr[i];
            }
        }

        return ans;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = INT_MIN;
        int high = 0;

        for(int i=0;i<nums.size();i++){
            low = max(low, nums[i]);
            high += nums[i];
        }

        int ans = high;

        while(low <= high){
            int mid = low + (high - low)/2;

            int count = arra(nums, mid);

            if(count > k){
                low = mid + 1;
            }
            else{
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};
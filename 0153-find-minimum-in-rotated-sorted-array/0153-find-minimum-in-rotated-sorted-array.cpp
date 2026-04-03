class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        int ans = INT_MAX;
        while(low<=high){
            mid = low + (high-low)/2;
            ans = min(ans,nums[mid]);
            if(nums[low]<nums[mid]){
                ans = min(nums[low],ans);
                low = mid + 1;
            }
            else{
                ans = min(nums[high],ans);
                high = mid-1;
            }
        }
        return ans;
    }
};
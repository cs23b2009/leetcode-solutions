class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        int first = -1;
        int last = -1;
        vector<int> ans;
        while(low<=high){
            mid = low + (high-low)/2;
            if(nums[mid]==target){
                first = mid;
                high = mid-1;
            }
            else if (nums[mid]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        low = 0;
        high = nums.size()-1;
        while(low<=high){
            mid = low + (high-low)/2;
            if(nums[mid]==target){
                last = mid;
                low = mid+1;
            }
            else if (nums[mid]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        ans.push_back(first);
        ans.push_back(last);
        return ans;

    }
};
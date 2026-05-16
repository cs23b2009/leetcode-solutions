class Solution {
public:
    bool condition(vector<int>&nums,int mid , int threshold){
        int count = 0;
        for(int i=0;i<nums.size();i++){
            count += (nums[i]+mid-1 )/ mid;
        }
        if(count<=threshold){
                return true;
            }
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = INT_MIN;
        for(int i=0;i<nums.size();i++){
            high = max(high,nums[i]);
        }
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(condition(nums,mid,threshold)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
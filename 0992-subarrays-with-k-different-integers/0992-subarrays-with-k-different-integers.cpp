class Solution {
public:
    int summ(vector<int>& nums,int k){
        if(k<0) return 0;
        int left = 0;
        int count = 0;
        unordered_map<int,int>mpp;
        for(int right=0;right<nums.size();right++){
            mpp[nums[right]]++;
            while(mpp.size()>k){
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0){
                    mpp.erase(nums[left]);
                }
                left++;
            }
            count += right - left+1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return summ(nums,k)-summ(nums,k-1);
    }
};
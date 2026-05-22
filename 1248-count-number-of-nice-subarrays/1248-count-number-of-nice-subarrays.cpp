class Solution {
public:
    int summ(vector<int>& nums, int k){
        if(k<0) return 0;
        int left = 0;
        int count = 0;
        int oddcount = 0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]%2==1){
                oddcount++;
            }
            while(oddcount>k){
                if(nums[left]%2==1){
                    oddcount--;
                }
                left++;
            }
            count += right-left+1;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return summ(nums,k) - summ(nums,k-1);
    }
};
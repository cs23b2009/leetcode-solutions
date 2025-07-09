class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        if(nums.size()==0) return 0;
        int l = 0;
        int maxlen = 0;
        int count = 0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]==0) count++;
            while(count>k){
                if(nums[l]==0) count --;
                l++;
            }
            maxlen = max(maxlen,r-l+1);
        }
        return maxlen;
    }
};
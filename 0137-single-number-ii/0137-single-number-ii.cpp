class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = nums[nums.size()-1];
        for(int i=1;i<nums.size();i=i+3){
            if(nums[i]!=nums[i-1]) {
                ans = nums[i-1];
                break;
            }
        }
        return ans;
    }
};
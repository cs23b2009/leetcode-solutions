class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0 ;
        int max_val = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
                max_val = max(max_val,count);
            }
            else{
                count = 0;
            }
        }
        return max_val;
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = nums[0];
        int prev2 = nums[0];
        int current = 0;
        for(int i=1;i<nums.size();i++){
            int pick = nums[i];
            if(i>1){
                pick += prev2 ;
            }
            int notpick = prev1;
            current = max(pick,notpick);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};
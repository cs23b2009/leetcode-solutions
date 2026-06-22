class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0;
        int prev = 0;
        for(int i=0;i<n;i++){
            int pick = nums[i];
            int nonpick = INT_MIN;
            if(i>1) pick += prev2;
            if(i>0) nonpick = prev;
            int curr = max(pick,nonpick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        int prev = 0;
        int prev2 = 0;
        int ans = 0;
        for(int i=0;i<n-1;i++){
            int pick = nums[i];
            if(i>1) pick += prev2;
            int nonpick = INT_MIN;
            if(i>0) nonpick = prev;
            int curr = max(pick,nonpick);
            prev2 = prev;
            prev = curr;
        }
        ans = max(ans,prev);
        prev = 0;
        prev2 = 0;
        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i>1) pick += prev2;
            int nonpick = INT_MIN;
            if(i>0) nonpick = prev;
            int curr = max(pick,nonpick);
            prev2 = prev;
            prev = curr;
        }
        ans = max(ans,prev);
        return ans;
    }
};
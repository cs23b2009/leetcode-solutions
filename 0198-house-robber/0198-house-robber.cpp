class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        int curr , prev1 , prev2;
        curr = prev1 = prev2 = nums[0];
        for(int i=0;i<n;i++){
            int take = nums[i];
            if(i>1) take += prev2;
            int nottaken = prev1;
            curr = max(take,nottaken);
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};
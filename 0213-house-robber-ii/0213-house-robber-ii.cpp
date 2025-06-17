class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int curr , prev1 , prev2;
        curr = prev1 = prev2 = nums[0];
        for(int i=0;i<n-1;i++){
            int take = nums[i];
            if(i>1) take += prev2;
            int nottaken = prev1;
            curr = max(take,nottaken);
            prev2 = prev1;
            prev1 = curr;
        }
        int curr1 ;
        prev1 = nums[1];
        prev2 = 0;
        for(int i=2;i<n;i++){
            int take = nums[i];
            if(i>1) take += prev2;
            int nottaken = prev1;
            curr1 = max(take,nottaken);
            prev2 = prev1;
            prev1 = curr1;
        }
        return max(curr1,curr);
    }
};
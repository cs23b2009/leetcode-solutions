class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        if(sum%2==0){
            sum /= 2;
        }
        else{
            return false;
        }
        vector<bool>prev(sum+1,false);
        vector<bool>curr(sum+1,false);
            prev[0] = true;
            curr[0] = true;
        if(nums[0]<=sum){
            prev[nums[0]] = true;
            curr[nums[0]] = true;
        }
        for(int i=1;i<nums.size();i++){
            for(int j=1;j<=sum;j++){
                bool pick = false;
                if(j>=nums[i]){
                    pick = prev[j-nums[i]];
                }
                bool nonpick = prev[j];
                curr[j] = pick || nonpick;
            }
            prev = curr;
        }
        return prev[sum];
    }
};
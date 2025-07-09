class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int> mpp;
        mpp[0] = 1;
        int presum = 0;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            presum += nums[i];
            int rem =  presum - goal;
            cnt += mpp[rem];
            mpp[presum] += 1;
        }
        return cnt;
    }
};
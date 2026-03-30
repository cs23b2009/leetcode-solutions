class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            int rem = target-nums[i];
            if(mpp.find(rem)!=mpp.end()){
                ans.push_back(mpp[rem]);
                ans.push_back(i);
                break;
            }
            mpp[nums[i]] = i;
        }
        return ans;
    }
};
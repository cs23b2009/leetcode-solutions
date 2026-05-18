class Solution {
public:
    void cur(int index,vector<int>& nums,vector<vector<int>>& ans,vector<int>&arr){
            ans.push_back(arr);
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]){
                continue;
            }
            arr.push_back(nums[i]);
            cur(i+1,nums,ans,arr);
            arr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int>arr;
        cur(0,nums,ans,arr);
        return ans;
    }
};
class Solution {
public: 
    void backtrack(vector<int>&nums,set<vector<int>>&ans,int ind){
        if(ind==nums.size()){
            ans.insert(nums);
        }
        for(int i=ind ;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            swap(nums[i],nums[ind]);
            backtrack(nums,ans,ind+1);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        backtrack(nums,ans,0);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        int subsets = 1<<size;
        vector<vector<int>> ans;
        for(int i=0;i<=subsets-1;i++){
            vector<int> ans1;
            for(int j=0;j<size;j++){
                if((i&1<<j)!=0) ans1.push_back(nums[j]);
            }
            ans.push_back(ans1);
        }
        return ans;
    }
};
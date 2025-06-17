class Solution {
public:
    void backtrack(vector<int>& nums, int ind, vector<vector<int>>& ans, vector<int>& doop) {
        ans.push_back(doop);  // Add the current subset

        for (int i = ind; i < nums.size(); i++) {
            if (i > ind && nums[i] == nums[i - 1]) continue;  // Skip duplicates
            doop.push_back(nums[i]);
            backtrack(nums, i + 1, ans, doop);  // Use i+1 to move to next element
            doop.pop_back();  // Backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Sort to handle duplicates
        vector<int> doop;
        vector<vector<int>> ans;
        backtrack(nums, 0, ans, doop);
        return ans;
    }
};
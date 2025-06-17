class Solution {
public:
    void backtrack(int ind, vector<int>& candidates, int target, vector<int>& curr, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        if (ind >= candidates.size()) return;

        if (candidates[ind] <= target) {
            curr.push_back(candidates[ind]);
            backtrack(ind, candidates, target - candidates[ind], curr, ans); // allow reuse
            curr.pop_back();
        }

        backtrack(ind + 1, candidates, target, curr, ans); // skip current
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(0, candidates, target, curr, ans);
        return ans;
    }
};
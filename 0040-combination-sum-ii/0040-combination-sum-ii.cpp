class Solution {
public:
    void recur(int index, vector<int>& candidates, int target,
               vector<int>& arr, vector<vector<int>>& ans) {

        if(target == 0) {
            ans.push_back(arr);
            return;
        }

        for(int i = index; i < candidates.size(); i++) {

            // skip duplicates
            if(i > index && candidates[i] == candidates[i - 1])
                continue;

            if(candidates[i] > target)
                break;

            arr.push_back(candidates[i]);

            recur(i + 1, candidates, target - candidates[i], arr, ans);

            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> arr;

        recur(0, candidates, target, arr, ans);

        return ans;
    }
};
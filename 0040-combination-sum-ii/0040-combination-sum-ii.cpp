class Solution {
public:
    void recursionn(int ind, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& arr) {
        if(target == 0) {
            ans.push_back(arr);
            return;
        }

        for(int i = ind; i < candidates.size(); i++) {

            if(i > ind && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if(candidates[i] > target) {
                break;
            }

            arr.push_back(candidates[i]);

            recursionn(i + 1, candidates, target - candidates[i], ans, arr);

            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> arr;

        recursionn(0, candidates, target, ans, arr);

        return ans;
    }
};
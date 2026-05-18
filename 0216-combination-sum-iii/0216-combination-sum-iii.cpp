class Solution {
public:
    void recur(int index, vector<int>& candidates, int target,
               vector<int>& arr, vector<vector<int>>& ans,int k) {

        if(target == 0 and k==arr.size()) {
            ans.push_back(arr);
            return;
        }
        

        for(int i = index; i < candidates.size(); i++) {

            // skip duplicates
            if(i > index && candidates[i] == candidates[i - 1])
                continue;

            // no need to continue further
            if(candidates[i] > target)
                break;

            arr.push_back(candidates[i]);

            recur(i + 1, candidates, target - candidates[i], arr, ans,k);

            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k , int target) {
        vector<int>candidates{1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> arr;

        recur(0, candidates, target, arr, ans,k);

        return ans;
    }
};
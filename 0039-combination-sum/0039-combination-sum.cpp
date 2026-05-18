class Solution {
public:
    void recursionn(int ind,vector<int>& candidates,int target,vector<vector<int>>& ans,vector<int>&arr){
        if(target==0){
            ans.push_back(arr);
            return;
        }
        if(ind>=candidates.size()){
            return;
        }
        if(candidates[ind]<=target){
            arr.push_back(candidates[ind]);
            recursionn(ind,candidates,target-candidates[ind],ans,arr);
            arr.pop_back();
        }
           recursionn(ind+1,candidates,target,ans,arr); 
    }

   
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>arr;
        recursionn(0,candidates,target,ans,arr); 
        return ans;
    }
};
class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char,int> mpp;

        for(auto it : s){
            mpp[it]++;
        }

        vector<pair<int,char>> arr;

        for(auto it : mpp){
            arr.push_back({it.second,it.first});
        }

        sort(arr.rbegin(), arr.rend());

        string ans = "";

        for(int i=0;i<arr.size();i++){

            while(arr[i].first > 0){

                ans += arr[i].second;

                arr[i].first--;
            }
        }

        return ans;
    }
};
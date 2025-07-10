class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorv = 0;
        for(auto it: nums){
            xorv ^= it;
        }
        int no = (xorv & (xorv -1)) ^ xorv;
        int bnt1 = 0;
        int bnt2 = 0;
        for(auto it:nums){
            if(it&no){
                bnt1 ^= it;
            }
            else{
                bnt2 ^= it;
            }
        }
        vector<int> ans;
        ans.push_back(bnt1);
        ans.push_back(bnt2);
        return ans;
    }
};
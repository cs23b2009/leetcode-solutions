class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<32;i++){
            int cnt = 0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]&1<<i) cnt++;
            }
            if(cnt%3==1) {
                ans = ans | 1<<i;
            }
        }
        if(ans >= (1 << 31)) {
            ans -= (1LL << 32);
        }
        return ans;
    }
};
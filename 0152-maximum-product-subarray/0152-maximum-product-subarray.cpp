class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n,0);
        vector<long long> suffix(n,0);
        int mul = 1;
        for(int i=n-1;i>=0;i--){
            mul *= nums[i];
            suffix[i] = mul;
            if(mul == 0) mul = 1;
        }
        mul = 1;
        for(int i=0;i<n;i++){
            mul *= nums[i];
            prefix[i] = mul;
            if(mul == 0) mul = 1;
        }
        long long maxprod = INT_MIN;
        for(int i=0;i<n;i++){
            maxprod = max(maxprod,max(prefix[i],suffix[i]));
        }
        return maxprod;
    }
};
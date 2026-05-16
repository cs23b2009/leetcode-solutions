class Solution {
public:
    bool condition(vector<int>&weights,long long mid,int days){
        long long sum = 0;
        int reqdays = 1;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]<=mid){
                sum += weights[i];
            }
            else{
                sum = weights[i];
                reqdays++;
            }
        }
        if(reqdays<=days){
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN;
        int high = 0;
        for(int i=0;i<weights.size();i++){
            low = max(low,weights[i]);
            high += weights[i];
        }
        int ans = high;
        while(low<=high){
            long long mid = low + (high-low)/2;
            if(condition(weights,mid,days)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
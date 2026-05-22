class Solution {
public:
    int characterReplacement(string s, int k) {
        int len =0;
        int left = 0;
        int maxFreq = INT_MIN;
        unordered_map<char,int>mpp;
        for(int right=0;right<s.size();right++){
            mpp[s[right]]++;
            maxFreq = max(maxFreq, mpp[s[right]]);
            while((right-left+1-maxFreq )>k){
                mpp[s[left]]--;
                if(mpp[s[left]]==0){
                    mpp.erase(s[left]);
                }
                left++;
            }
            len = max(len,right-left+1);
        }
        return len;
    }
};
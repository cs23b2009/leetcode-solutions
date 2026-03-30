class Solution {
public:
    bool checkStrings(string s1, string s2) {
        map<char,int> mpp1;
        map<char,int> mpp2;
        for(int i=0;i<s1.size();i=i+2){
            mpp1[s1[i]]++;
        }
         for(int i=1;i<s1.size();i=i+2){
            mpp2[s1[i]]++;
        }
         for(int i=0;i<s2.size();i=i+2){
            if(mpp1.find(s2[i])!=mpp1.end() && mpp1[s2[i]]>0){
                mpp1[s2[i]]--;
            }
            else{
                return false;
            }
        }
         for(int i=1;i<s2.size();i=i+2){
            if(mpp2.find(s2[i])!=mpp2.end() && mpp2[s2[i]]>0){
                mpp2[s2[i]]--;
            }
            else{
                return false;
            }
        }
        return true;

    }
};
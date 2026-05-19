class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        int lastindex = -1;
        for(int i=num.length();i>=0;i--){
            if(num[i]%2==1){
                lastindex=i;
                break;
            }
        }
        if(lastindex!=-1){
            for(int i=0;i<=lastindex;i++){
            ans+=num[i];
        }
        }
        return ans;
    }
};
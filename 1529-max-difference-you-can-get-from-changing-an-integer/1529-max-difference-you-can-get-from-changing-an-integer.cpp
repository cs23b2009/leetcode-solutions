class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string aStr = s;
        char toReplaceA = 0;
        for(char c : s){
            if(c != '9'){
                toReplaceA = c;
                break;
            }
        }
        if(toReplaceA){
            for(char &c : aStr){
                if(c == toReplaceA) c = '9';
            }
        }
        int a = stoi(aStr);
        string bStr = s;
        char toReplaceB = 0;
        if(s[0] != '1'){
            toReplaceB = s[0];
            for(char &c : bStr){
                if(c == toReplaceB) c = '1';
            }
        }
        else{
            for(int i = 1; i < s.size(); ++i){
                if(s[i] != '0' && s[i] != '1'){
                    toReplaceB = s[i];
                    break;
                }
            }
            if(toReplaceB){
                for(int i = 1; i < bStr.size(); ++i){
                    if(bStr[i] == toReplaceB) bStr[i] = '0';
                }
            }
        }
        int b = stoi(bStr);
        
        return a - b;
    }
};
class Solution {
public:
    string rotate(string newone,int index){
        string s = newone;
        reverse(s.begin(),s.begin()+index);
        reverse(s.begin()+index,s.end());
        reverse(s.begin(),s.end());
        return s;
    }
    bool rotateString(string s, string goal) {
        if(s==goal) return true;
        for(int i=0;i<s.length()-1;i++){
            string newone = rotate(s,i+1);
            if(newone==goal){
                return true;
            }
        }
        return false;
    }
};
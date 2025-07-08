class Solution {
public:
    bool isAlpha(char s) {
    return ('a' <= s && s <= 'z') || ('A' <= s && s <= 'Z') || ('0' <= s && s <= '9');
}

   
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        while(start<end){
            if(!isAlpha(s[start])){
                start ++ ;
                continue;
            }
            if(!isAlpha(s[end])){
                end--;
                continue;
            }
            if(tolower(s[start])!=tolower(s[end])) return false;
            start++;
            end--;
        }
        return true;
    }
};
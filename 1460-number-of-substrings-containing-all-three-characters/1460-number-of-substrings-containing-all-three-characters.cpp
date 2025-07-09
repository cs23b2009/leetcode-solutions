class Solution {
public:
    int numberOfSubstrings(string s) {
        int no = 0;
        int n = s.length();
        unordered_map<int, int> mpp = { {0, -1}, {1, -1}, {2, -1} };
        for(int i=0;i<n;i++){
            mpp[s[i]-'a'] = i;
            if(mpp[0]>=0 && mpp[1]>=0 && mpp[2]>=0 ){
                int minele = min(mpp[0],min(mpp[1],mpp[2]));
                no += minele + 1;
            }
        }
        return no;
    }
};
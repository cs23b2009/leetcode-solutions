class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxlen = 0;
        int l = 0;
        int ele1 = -1;
        int ele2 = -1;
        for(int r = 0;r<n;r++){
            if(ele1==-1 && ele2==-1){
                ele1 = fruits[r];
            }
            if(ele1!=fruits[r]){
                if(ele2==-1){
                    ele2 = fruits[r];
                }
                else if(ele2!=fruits[r]){
                    ele2 = fruits[r];
                    int pointer = r-1;
                    ele1 = fruits[r-1];
                    while(pointer > l){
                        if(fruits[pointer]!=ele1) break;
                        pointer--;
                    }
                    l = pointer+1;
                }
            }
            maxlen = max(maxlen,r-l+1);
        }
        return maxlen;
    }
};
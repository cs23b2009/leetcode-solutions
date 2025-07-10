class Solution {
public:
    int minBitFlips(int start, int goal) {
        int no = start^goal;
        int count = 0;
        while(no!=0){
            no = no & no-1;
            count++;
        }
        return count;
    }
};
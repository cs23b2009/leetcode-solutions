class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int left = 0;
        int right =1;
        while(right<=arr.size()-1){
            if(arr[right]==arr[left]){
                right++;
            }
            else{
                left++;
                arr[left]=arr[right];
                right ++ ;
            }
        }
        return left+1;
    }
};
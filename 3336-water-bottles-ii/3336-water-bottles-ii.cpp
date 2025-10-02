class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;  
        int empty = numBottles;
        int ex = numExchange;

        while (empty >= ex) {
            empty -= ex;
            ex++;         
            ans++;       
            empty++;      
        }

        return ans;
    }
};
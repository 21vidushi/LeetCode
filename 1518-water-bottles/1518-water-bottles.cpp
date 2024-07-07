class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
           int ans=numBottles;
        int r = numBottles % numExchange;
        int d = numBottles / numExchange;

        while((r+d)>=numExchange){
            ans+=d;
            numBottles = (d+r);
            d = numBottles / numExchange;
            r = numBottles % numExchange;
        }
        return ans+d;
    }
};
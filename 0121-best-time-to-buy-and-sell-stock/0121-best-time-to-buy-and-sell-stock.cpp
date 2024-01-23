class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int profit=0;
        for(int i=0;i<prices.size();i++){
            int curr=prices[i];
            int diff=curr-mini;
            mini=min(curr,mini);
            profit=max(profit,diff);
        }
        return profit;
    }
};
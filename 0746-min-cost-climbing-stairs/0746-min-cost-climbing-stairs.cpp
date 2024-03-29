class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int prev=cost[0],prev1=cost[1];
        if(n<=2) return min(prev,prev1);
        for(int i=2;i<n;i++){
            int curr=cost[i]+min(prev,prev1);
            prev=prev1;
            prev1=curr;
        }
        return min(prev,prev1);
    }
};


class Solution {
public:
    int climbStairs(int n) {
       if(n<=1) return 1;
        
        int prev=1,prev1=1;
        for(int i=2;i<=n;i++){
            int curr=prev+prev1;
            prev1=prev;
            prev=curr;
        }
        return prev;
    }
};
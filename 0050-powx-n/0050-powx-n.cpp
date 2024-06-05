class Solution {
public:
    double myPow(double x, int m) {
        int n= abs(m);
        double ans=1;
        if(n==0) return 1;
        if(n%2==0){
            ans= myPow(x,n/2);
            ans=ans*ans;
        }
        else{
            ans= x*myPow(x,n-1);
        }
        if(m<0) return 1.0/ans;
        return ans;
    }
};
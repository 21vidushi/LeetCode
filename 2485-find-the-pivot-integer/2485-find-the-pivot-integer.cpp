class Solution {
public:
    int pivotInteger(int n) {
        int total=n*(n+1)/2;
        int low=1,high=n;
        while(low<=high){
            int mid= low+(high-low)/2;
            int sum1=mid*(mid+1)/2;
             int sum2=total-sum1+mid;
            if(sum1==sum2) return mid;
            else if(sum1<sum2) low=mid+1;
            else high=mid-1;
            
        }
        return -1;
    }
};
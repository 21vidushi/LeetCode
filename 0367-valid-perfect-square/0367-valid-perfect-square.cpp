class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1) return true;
       long long int low=1,high=num/2;
        while(low<=high){
           long long int mid= low+(high-low)/2;
            long long check= mid*mid;
            
            if(check==(long long)num) return true;
            else if(check>(long long)num) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};
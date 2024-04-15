
class Solution {
    long gcd(long a,long b){
        if((a%b)==0)return b;
        else return gcd(b,a%b);
    }
public:
    int minimizeSet(int d1, int d2, int uc1, int uc2) {     
        long start = 1;
        long end = 1e10;
        long g = gcd(max(d1,d2),min(d1,d2));
        long l = (long(d1)*long(d2))/g;
        long ans = -1;
        while(start<=end){
            long m = (start +end)/2;
            long a = m-(m/d1);
            long b = m-(m/d2);
            long c = m-(m/d1)-(m/d2)+(m/l);
            if(a>=uc1 && b>=uc2 && a+b-c>=uc1+uc2){
                ans = m;
                end= m-1;
            }else{
                start = m+1;
            }
        }
        return (int)ans;
    }
};
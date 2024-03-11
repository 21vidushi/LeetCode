class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xoro=start^goal;
        int cnt=0;
        while(xoro!=0){
            cnt+=xoro&1;
            xoro>>=1;
        }
        return cnt;
    }
};
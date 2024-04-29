class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xoro=0;
        for(int i=0;i<nums.size();i++){
            xoro^=nums[i];
        }
        int res=xoro^k;
        int i=1,cnt=0;
        while(res!=0){
            if(1&res) cnt++;
             res>>=i;
        }
        return cnt;
    }
};
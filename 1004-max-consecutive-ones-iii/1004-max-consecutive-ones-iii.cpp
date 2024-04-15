class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,maxlen=0,zero=0;
        while(r<nums.size()){
            if(nums[r]==0) zero++;
            if(zero>k){
                if(nums[l]==0){
                    zero--;
                }
                l++;
            }
            if(zero<=k){
                maxlen=max(r-l+1,maxlen);
            }
            r++;
        }
        return maxlen;
    }
};
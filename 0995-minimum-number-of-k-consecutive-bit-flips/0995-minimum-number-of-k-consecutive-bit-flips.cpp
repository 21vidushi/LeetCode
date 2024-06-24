class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int st = 0, en = k-1, ans = 0;
        vector<int> v(n, 0);
        int flips = 0;
        while(en < n){
            if((nums[st]^(flips%2)) == 0){
                flips++;
                ans++;
                if(en < n-1){
                    v[en+1] = 1;
                }
            }
            while(en < n and (nums[st]^(flips%2)) == 1){
                st++; en++;
                if(st<n)
                flips += v[st];
            }
        }
        if(st<n)
        flips -= v[st];
        while(st<n){
            if((nums[st]^((flips+v[st])%2)) == 0)return -1;
            flips += v[st];
            st++;
        }
        return ans;
    }
};
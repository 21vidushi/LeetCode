class Solution {
public:
    int find(vector<int>& nums, int k){
        int count=0,odd=0;
        int i=0,j=0;
        while(i<nums.size()){
            if(nums[i]%2!=0){
                odd++;
            }
            while(odd>k&&j<=i){
                if(nums[j]%2!=0){
                    odd--;
                }
                j++;
            }
            if(odd<=k) count+=(i-j+1);
            i++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return find(nums,k)-find(nums,k-1);
    }
};
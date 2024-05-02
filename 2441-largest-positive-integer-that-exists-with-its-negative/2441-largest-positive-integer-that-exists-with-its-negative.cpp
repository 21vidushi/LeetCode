class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            if(nums[i]<0) return -1;
            else{
                if(find(nums.begin(),nums.end(),-nums[i])!=nums.end()) return nums[i];
            }
        }
        return -1;
    }
};
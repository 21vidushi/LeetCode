class Solution {
public:
    int find(vector<int>& nums, int k){
        int count=0,sum=0;
        int i=0,j=0;
        while(i<nums.size()){
            sum+=nums[i];
            while(sum>k&&j<=i){
                if(nums[j]==1) sum--;
                j++;
            }
            if(sum<=k){
              count+=(i-j+1);
            }
            i++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return find(nums,goal)-find(nums,goal-1);
    }
};
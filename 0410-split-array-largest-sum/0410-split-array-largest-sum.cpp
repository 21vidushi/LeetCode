class Solution {
public:
    int find(vector<int>& nums, int count){
        int n=nums.size();
        int c=1,alocate=0;
        for(int i=0;i<nums.size();i++){
            if(alocate+nums[i]<=count){
                alocate+=nums[i];
            }
            else {
                c++;
                alocate=nums[i];
            }
        }
        return c;
    }
    int splitArray(vector<int>& nums, int k) {
        int low= *max_element(nums.begin(),nums.end());
        int high= accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            int number= find(nums,mid);
            if(number>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};
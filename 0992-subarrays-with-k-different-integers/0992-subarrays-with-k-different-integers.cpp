class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int i=0,j=0,count=0;
        unordered_map<int,int> mpp;
        while(i<nums.size()){
            mpp[nums[i]]++;
            while(mpp.size()>k){
                auto it= mpp.find(nums[j]);
                it->second--;
                if(it->second==0) mpp.erase(it);
                j++;
            }
            count+=(i-j+1);
            i++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)- atmost(nums,k-1);
    }
};
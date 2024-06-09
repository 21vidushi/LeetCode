class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0]=-1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mpp.find(sum%k)!=mpp.end()&&(i-mpp[sum%k])>1) return true;
            else if(mpp.find(sum%k)==mpp.end()) mpp[sum%k]=i;
            
        }
        return false;
        
    }
};
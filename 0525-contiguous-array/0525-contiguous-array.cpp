class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       unordered_map<int,int> mpp;
        int sum=0,maxlen=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i]==0?-1:1;
            if(sum==0){
                maxlen=i+1;
            }
            else if(mpp.find(sum)!=mpp.end()){
                maxlen=max(maxlen,i-mpp[sum]);
            }
            else
            mpp[sum]=i;
        }
        return maxlen;
    }
};
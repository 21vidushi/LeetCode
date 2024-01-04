class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            if(it.second==1) return -1;
            ans+=it.second/3;
            if(it.second%3) ans++;
            }
        
        return ans;
    }
};
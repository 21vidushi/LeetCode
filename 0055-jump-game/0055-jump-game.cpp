class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int fur=0;
        for(int i=0;i<nums.size();i++){
            if(i>fur) return false;
            fur=max(fur,i+nums[i]);
            if(fur>=n-1) return true;
        }
        return true;
    }
};
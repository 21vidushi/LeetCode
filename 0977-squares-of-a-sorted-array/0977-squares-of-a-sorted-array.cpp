class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int pos=INT_MAX,neg=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                pos=i;
                neg=i-1;
                break;
            }
        }
       
        if(pos==INT_MAX) neg=n-1;
        while(pos<n&&neg>=0){
            if(nums[pos]>abs(nums[neg])){
                ans.push_back(nums[neg]*nums[neg]);
                neg--;
            }
            else{
                ans.push_back(nums[pos]*nums[pos]);
                pos++;
            }
        }
        while(pos<n){
              ans.push_back(nums[pos]*nums[pos]);
                pos++;
        }
        while(neg>=0){
             ans.push_back(nums[neg]*nums[neg]);
                neg--;
        }
        return ans;
    }
};
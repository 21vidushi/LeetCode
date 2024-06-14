class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i + 1] = nums[i + 1] + 1;
                ans = ans + 1;
            } else if (nums[i] > nums[i + 1]) {
                ans = (nums[i] - nums[i + 1]) + 1+ans;
                nums[i + 1] = nums[i + 1] + (nums[i] - nums[i + 1]) + 1;
            }
            cout<<nums[i]<<endl;
        }
        return ans;
                
    }
};
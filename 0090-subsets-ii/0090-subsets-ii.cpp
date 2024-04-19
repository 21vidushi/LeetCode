class Solution {
public:
    void find(vector<int>& nums, int i, set<vector<int>>& ans, vector<int> temp) {
        if (i == nums.size()) {
            sort(temp.begin(), temp.end());
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        find(nums, i + 1, ans, temp); // Include the current element
        temp.pop_back();
        find(nums, i + 1, ans, temp); // Exclude the current element
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;
        find(nums, 0, ans, temp);
        return {ans.begin(), ans.end()};
    }
};

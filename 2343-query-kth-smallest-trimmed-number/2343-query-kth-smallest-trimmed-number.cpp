class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int len= nums[0].size();
        for(int i=0;i<queries.size();i++){
            int k=queries[i][0];
            int trim= queries[i][1];
            vector<pair<string,int>> temp;
            for(int i=0;i<nums.size();i++){
                string sub= nums[i].substr(len-trim);
                temp.push_back({sub,i});
            }
            sort(temp.begin(),temp.end());
            ans.push_back(temp[k-1].second);
        }
        return ans;
    }
};
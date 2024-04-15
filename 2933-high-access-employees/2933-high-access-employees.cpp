class Solution {
public:
    bool isValid(vector<int> &nums){
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i+2]-nums[i]<60) return true;
        }
        return false;
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> ans;
        unordered_map<string,vector<int>> mpp;
        for(auto it: access_times){
            string hours= it[1].substr(0,2);
            string minu=it[1].substr(2,2);
            int total=stoi(hours)*60+stoi(minu);
            mpp[it[0]].push_back(total);
        }
        
        for(auto it:mpp){
            if(it.second.size()<3){
                continue;
            }
            sort(it.second.begin(),it.second.end());
            if(isValid(it.second)){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
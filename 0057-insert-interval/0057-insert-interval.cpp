class Solution {
public:
    bool static comp(vector<int>&v1,vector<int>&v2){
        return v1[0]<v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& v){
        vector<vector<int>> ans;
        ans.push_back(v[0]);
        for(int i=1;i<v.size();i++){
            if(ans.back()[1]>=v[i][0]){
                ans.back()[1]=max(ans.back()[1],v[i][1]);
            }
            else{
                ans.push_back(v[i]);
            }
        }
        return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            intervals.push_back(newInterval);
            sort(intervals.begin(),intervals.end(),comp);
        vector<vector<int>>res= merge(intervals);
        return res;
    }
};
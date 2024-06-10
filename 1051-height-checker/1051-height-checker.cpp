class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ans=0;
        vector<int> expected(heights.begin(),heights.end());
        sort(expected.begin(),expected.end());
        for(int i=0;i<heights.size();i++ ){
            if(heights[i]!=expected[i]) ans++;
        }
        return ans;
    }
};
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>>st;
        for(int i=0;i<nums.size();i++){
            int cnt=0;
             vector<int> v;
            for(int j=i;j<nums.size();j++){
                v.push_back(nums[j]);
                if(nums[j]%p==0) cnt++;
                if(cnt>k) break;
                st.insert(v);
                
                
            }
          
        }
        return st.size();
    }
};
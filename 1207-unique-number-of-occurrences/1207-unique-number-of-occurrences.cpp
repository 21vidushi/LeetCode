class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        set<int> st;
        for(auto it:mpp){
            st.insert(it.second);
        }
        if(st.size()==mpp.size()) return true;
        else  return false;
    }
};
 unordered_map<char,int> mpp;
    bool cmp(const char &ele1,const char &ele2){
         return mpp[ele1]<mpp[ele2];
    }
class Solution {
public:
    string customSortString(string order, string s) {
      
        for(int i=0;i<order.size();i++){
            mpp[order[i]]=i;
        }
        sort(s.begin(),s.end(),cmp);
        return s;
    }
};

class Solution {
public:
   static bool cmp(pair<char,int>&p1,pair<char,int> &p2){
       return p1.second>p2.second;
   }
    string frequencySort(string s) {
        string ans="";
        unordered_map<char,int> mpp;
        for(int i=0;i<s.length();i++){
            mpp[s[i]]++;
        }
        vector<pair<char,int>> vc(mpp.begin(),mpp.end());
        sort(vc.begin(),vc.end(),cmp);
        for(auto it:vc){
            while(it.second!=0){
                ans+=it.first;
                it.second--;
            }
        }
        return ans;
    }
};
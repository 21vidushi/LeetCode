class Solution {
public:
   static bool comp(pair<int,int>&p1,pair<int,int>&p2){
        return p1.second>p2.second;
    }
    string frequencySort(string s) {
        string ans="";
        unordered_map<char,int>mpp;
        for(int i=0;i<s.length();i++){
            mpp[s[i]]++;
        }
       vector<pair<int,int>>v(mpp.begin(),mpp.end());
        sort(v.begin(),v.end(),comp);
        for(auto it:v){
            while(it.second!=0){
            ans+=it.first;
                it.second--;
        }
        }
        return ans;
    }
};
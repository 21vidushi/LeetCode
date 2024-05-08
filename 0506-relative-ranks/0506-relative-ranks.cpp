class Solution {
public:
    bool static comp(pair<int,int>&p1,pair<int,int>&p2){
        return p1.second>p2.second;
    }
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string> ans(n);
        vector<pair<int,int>>v;
        for(int i=0;i<score.size();i++){
            v.push_back({i,score[i]});
        }
        sort(v.begin(),v.end(),comp);
        int i=0;
        for(auto it:v){
            if(i==0){
                ans[it.first]="Gold Medal";
            }
           else if(i==1){
                ans[it.first]="Silver Medal";
            }
           else if(i==2){
                ans[it.first]="Bronze Medal";
            }
            else ans[it.first]= to_string(i+1);
            i++;
        }
       return ans;
        
    }
};
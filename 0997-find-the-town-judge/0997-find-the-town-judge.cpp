class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusts(n+1,0);
        vector<int> trusted(n+1,0);
        for(int i=0;i<trust.size();i++){
            trusts[trust[i][0]]++;
            trusted[trust[i][1]]++;
        }
        for(int i=1;i<n+1;i++){
            if(trusts[i]==0&&trusted[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};
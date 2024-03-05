class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size(),m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0;
        int count=0;
        while(i<n&&j<m){
            if(s[j]>=g[i])
            {
                count++;
                j++;
                i++;
            }
           else{
               j++;
           }
        }
        return count;
    }
};
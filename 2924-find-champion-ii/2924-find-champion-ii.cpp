class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int ans=-1,cnt=0;
        vector<int> visited(n,0);
        for(int i=0;i<edges.size();i++){
            visited[edges[i][1]]++;
        }
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                ans=i;
                cnt++;
            }
        }
        if(cnt==1) return ans;
        else return -1;
        
    }
};
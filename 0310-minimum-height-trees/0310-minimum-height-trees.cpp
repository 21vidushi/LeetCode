class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<int> ans;
        vector<int>degree(n,0);
        unordered_map<int,vector<int>>adj;
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
             adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
            
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(degree[i]==1){
                q.push(i);
            }
        }
        
        while(n>2){
            int size=q.size();
            n-=size;
            for(int i=0;i<size;i++){
                int fronti= q.front();
                q.pop();
                for(auto it:adj[fronti]){
                    degree[it]--;
                    if(degree[it]==1) q.push(it);
                }
            }
        }
        while(!q.empty()){
            int a= q.front();
            q.pop();
            ans.push_back(a);
        }
        return ans;
    }
};
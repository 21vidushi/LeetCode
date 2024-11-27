class Solution {
public:
    int bfs(vector<vector<int>>& adj, int n){
        vector<int> visited(n,1e9);
        queue<int> q;
        visited[0]=0;
        q.push(0);
        while(!q.empty()){
            int node= q.front();
            q.pop();
        for(auto it: adj[node]){
             int dist= visited[node] + 1;
             if(dist < visited[it]){
              visited[it]=dist;
              q.push(it);
                }
            
            }
        }
        
        return visited[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        for(int i=0;i<queries.size();i++){
            adj[queries[i][0]].push_back(queries[i][1]);
           int ele= bfs(adj,n);
           ans.push_back(ele); 
        }
        return ans;
    }
};
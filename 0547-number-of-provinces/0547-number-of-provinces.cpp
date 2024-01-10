class Solution {
public:
    void createadj(vector<vector<int>> isConnected,vector<list<int>>& adj){
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
    }
    void dfs(int node,vector<list<int>> adj,map<int,bool>&visited){
        visited[node]=true;
        for(auto it:adj[node]){
            if(visited.find(it)==visited.end()){
                visited[it]=true;
                dfs(it,adj,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<list<int>> adj(n);
        createadj(isConnected,adj);
        map<int,bool>visited;
        int ans=0;
        for(int i=0;i<n;i++){
            if(visited.find(i)==visited.end()){
                ans++;
                dfs(i,adj,visited);
            }
        }
        return ans;
    }
};
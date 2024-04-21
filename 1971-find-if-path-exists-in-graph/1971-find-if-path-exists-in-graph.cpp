class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<int>vis(n,0);
        for (auto edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int front= q.front();
            vis[front]=1;
            q.pop();
            if(front==destination) return true;
            for(auto it: adj[front]){
                if(!vis[it])
                q.push(it);
            }
        }
        return false;
    }
};
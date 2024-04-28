class Solution {
    int size;
public:
    vector<int> ans;
    vector<int> cnt;

    void dfs(int src, int par, unordered_map<int,vector<int>>& adj) {
        for (auto &child : adj[src]) {
            if (child != par) {
                dfs(child, src, adj);
                cnt[src] += cnt[child];
                ans[src] += ans[child] + cnt[child];
            }
        }
        cnt[src]++;
    }

    void dfs1(int src, int par, unordered_map<int,vector<int>>& adj) {
        for (auto &child : adj[src]) {
            if (child != par) {
                ans[child] = ans[src] - cnt[child] + (size - cnt[child]);
                dfs1(child, src, adj);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        size = n;
        ans.resize(n, 0);
        cnt.resize(n, 0);
        unordered_map<int,vector<int>> adj;

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1, adj);
        dfs1(0, -1, adj);

        return ans;
    }
};

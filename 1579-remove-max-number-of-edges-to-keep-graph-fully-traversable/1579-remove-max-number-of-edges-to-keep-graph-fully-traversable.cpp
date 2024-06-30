class DSU {
private:
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void join(int x, int y) {
        int xSet = find(x), ySet = find(y);

        if (xSet == ySet)
            return;
        
        if (rank[xSet] >= rank[ySet]) {
            parent[ySet] = xSet;
            rank[xSet] += rank[ySet];
        } else {
            parent[xSet] = ySet;
            rank[ySet] += rank[xSet];
        }
    }

    bool isJoint(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int kept = 0, bobNodes = n - 1, aliceNodes = n - 1;
        DSU bob(n), alice(n);

        for (auto &e : edges) {
            int type = e[0], u = e[1] - 1, v = e[2] - 1;

            if (type == 3 && !alice.isJoint(u, v)) {
                alice.join(u, v); bob.join(u, v);
                aliceNodes--; bobNodes--; kept++;
            }
        }

        for (auto &e : edges) {
            int type = e[0], u = e[1] - 1, v = e[2] - 1;

            if (type == 1 && !alice.isJoint(u, v)) {
                alice.join(u, v);
                aliceNodes--; kept++;
            } else if (type == 2 && !bob.isJoint(u, v)) {
                bob.join(u, v);
                bobNodes--; kept++;
            }
        }

        return (aliceNodes == 0 && bobNodes == 0) ? edges.size() - kept : -1;
    }
};
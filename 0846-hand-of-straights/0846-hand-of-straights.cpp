class Solution {
public:


    bool isNStraightHand(vector<int>& a, int g) {
        int n = a.size();
        int k = n / g;
        if (k * g != n) {           // base case
            return false;
        }
        map<int, int>mp;
        for (auto x : a) {
            mp[x]++;
        }
        auto start = mp.begin();
        while (k--) {
            auto it = start;
            int curr = it->first;
            for (int i = 0; i < g; i++) {
                if (it->first != curr || it->second <= 0) {
                    return false;
                }
                it->second--;
                if (it->second == 0) {
                    start = it;
                    start++;
                }
                it++;
                curr++;
            }
        }
        return true;
    }
};
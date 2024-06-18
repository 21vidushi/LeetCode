#include <bits/stdc++.h>
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>>mp;
        for(int i=0; i<difficulty.size(); i++)
        {
            mp.push_back({difficulty[i], profit[i]});
        }
        sort(mp.begin(), mp.end());
        int sum = 0;
        for(int i=0; i<worker.size(); i++)
        {
            int prof = 0;
            int j = 0;
            while(j<difficulty.size() && worker[i] >= mp[j].first)
            {
                prof = max(prof, mp[j].second);
                j++;
            }
            sum += prof;
        }
        return sum;
    }
};
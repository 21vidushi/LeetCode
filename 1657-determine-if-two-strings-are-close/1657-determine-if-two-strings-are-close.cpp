class Solution {
public:
    bool closeStrings(std::string word1, std::string word2) {
        vector<int> mp1(26, 0), mp2(26, 0);
        for(auto i : word1) mp1[i - 'a']++;
        for(auto i : word2) mp2[i - 'a']++;
        // existence checking
        for (int i = 0; i < mp1.size(); i++) {
            if ((mp1[i] == 0 && mp2[i] != 0) || (mp1[i] != 0 && mp2[i] == 0)) {
                return false;
            }
        }
        // checking if we can swap
        sort(mp1.begin(), mp1.end());
        sort(mp2.begin(), mp2.end());
        return mp1 == mp2;
    }
};
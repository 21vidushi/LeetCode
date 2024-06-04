class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>m;
        for(auto itr:s){
            m[itr]++;
        }
        int c=0;
        bool hasOddFrequency=false;
        for (auto count : m) {
            c += count.second / 2 * 2; // Add even frequencies
            if (count.second % 2 == 1) {
                hasOddFrequency = true;
            }
        }
        if(hasOddFrequency) return c+1;
        return c;
    }
};
class Solution {
public:
    bool check(string s){
        int l=s.length();
        for(int i=0;i<l/2;i++){
            if(s[i]!=s[l-i-1]) return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        int l=words.size();
        for(int i=0;i<l;i++){
            if(check(words[i])) {
                return words[i];
            }
        }
        return "";
    }
};
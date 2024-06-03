class Solution {
public:
    int appendCharacters(string s, string t) {
        int n=s.length(),m=t.length();
        int match=0;
        int i=0,j=0;
        while(i<n&&j<m){
            if(s[i]==t[j]){
                i++;
                j++;
                match++;
            }
            else
                i++;
        }
        return m-match;
    }
};
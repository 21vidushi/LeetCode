class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt1=0,cnt2=0;
        int n=s.length();
        for(int i=0;i<n/2;i++){
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                    cnt1++;
                }
        }
        
        for(int i=n/2;i<n;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
                cnt2++;
        }
        return cnt1==cnt2;
    }
};
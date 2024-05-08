class Solution {
   
public:
     bool static cmp(string s1,string s2){
        return s1.size()<s2.size();
    }
    bool compare(string s1, string s2){
        int n1=s1.length(),n2=s2.length();
        if(n1!=n2+1) return false;
        int i=0,j=0;
        while(i<n1){
            if(j<n2&&s1[i]==s2[j]){i++; j++;}
            else {
                i++;}
        }
        if(i==n1&&j==n2) return true;
        else return false;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),cmp);
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(compare(words[i],words[prev])&&dp[prev]+1>dp[i]){
                    dp[i]=dp[prev]+1;
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};

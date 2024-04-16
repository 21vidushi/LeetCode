class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> hash(26,0);
        int i=0,j=0,maxlen=INT_MIN,maxfr=INT_MIN;
        while(i<s.size()){
            hash[s[i]-'A']++;
            maxfr=max(maxfr,hash[s[i]-'A']);
            while((i-j+1)-maxfr>k){
                hash[s[j]-'A']--;
                for(int i=0;i<26;i++){
                    maxfr=max(maxfr,hash[i]);
                }
                j++;
            }
            if((i-j+1)-maxfr<=k){
                maxlen=max(maxlen,i-j+1);
            }
            i++;
        }
        return maxlen;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;
        unordered_map<char,int>  mpp;
        int i=0,j=0;
        while(i<s.length()){
            if(mpp.find(s[i])!=mpp.end())
               j = max(j, mpp[s[i]] + 1);
             mpp[s[i]]=i;
             maxlen=max(maxlen,i-j+1);
            i++;
            }
           
      
        return maxlen;
    }
        
};
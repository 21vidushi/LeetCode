class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>mpp(256,0);
        for(int i=0;i<t.size();i++){
            mpp[t[i]]++;
        }
        int i=0,j=0,cnt=0,minlen=INT_MAX,sin=-1;
        while(i<s.size()){
            if(mpp[s[i]]>0) cnt++;
            mpp[s[i]]--;
            while(cnt==t.size()){
                if(i-j+1<minlen){
                    minlen=i-j+1;
                    sin=j;
                }
                mpp[s[j]]++;
                if(mpp[s[j]]>0) cnt--;
                j++;
            }
            i++;
        }
        return sin==-1? "":s.substr(sin,minlen);
    }
};
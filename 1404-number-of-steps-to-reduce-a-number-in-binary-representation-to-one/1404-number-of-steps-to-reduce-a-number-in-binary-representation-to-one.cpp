class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        while(s!="1"){
            if(s.back()=='0'){
               s.pop_back();
                ans++;
            }
            else{
               int carry=1;
                for(int i=s.length()-1;i>=0;i--){
                    if(s[i]=='1')
                        s[i]='0';
                    else{
                        s[i]='1';
                        carry=0;
                        break;
                    }
                }
                ans++;
                if(carry) s='1'+s;
            }
            
        }
        return ans;
    }
};
#include<bits/stdc++.h>
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        map<string,int>mp;
        for(int i=0;i<dictionary.size();i++) mp[dictionary[i]]++;
        sentence+=" ";
        string st="",s="";
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]!=' '){
                st+=sentence[i];
            }
            else{
                string st2="";bool b=true;
               for(int j=0;j<st.size();j++){
                   st2+=st[j];
                   if(mp.count(st2)>0){
                     s+=st2;
                     b=!b;
                     break;
                   }
               }
               if(b){
                 s+=st2;
               }
               s+=" ";
               st="";
            }
        }
        s.erase(s.length()-1,1);
        return s;
    }
};
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1;
        vector<string> v2;
        string rev="";
        for(int i=0;i<version1.size();i++){
            if(version1[i]=='.'){
                v1.push_back(rev);
                rev="";
            }
            else rev.push_back(version1[i]);
        }
        if(rev.size()>0) v1.push_back(rev); rev="";
        
        for(int i=0;i<version2.size();i++){
            if(version2[i]=='.'){
                v2.push_back(rev);
                rev="";
            }
            else rev.push_back(version2[i]);
        }
        if(rev.size()>0) v2.push_back(rev); rev="";
        
        int i=0,j=0;
        while(i<v1.size()&&j<v2.size()){
            int x= stoi(v1[i]);
            int y=stoi(v2[j]);
            
            if(x>y) return 1;
            if(x<y) return -1;
            i++;
            j++;
        }
        while(i<v1.size()){
            int x=stoi(v1[i]);
            if(x!=0) return 1;
            i++;
        }
         while(j<v2.size()){
            int x=stoi(v2[j]);
            if(x!=0) return -1;
            j++;
        }
        return 0;
        
    }
};
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(),deadends.end());
        unordered_map<string,int>mpp;
        queue<pair<string,int>>q;
        if(dead.find("0000")==dead.end()){
            mpp["0000"]=1;
            q.push({"0000",0});
        }
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            string s=f.first;
            int count=f.second;
            if(s==target) return count;
            for(int i=0;i<4;i++){
                string temp1,temp2;
                temp1=s.substr(0,i)+to_string((s[i]-'0'+1)%10)+ s.substr(i+1);
                temp2=s.substr(0,i)+ to_string((s[i]-'0'-1+10)%10)+s.substr(i+1);
                if(mpp.find(temp1)==mpp.end()&&dead.find(temp1)==dead.end()){
                    q.push({temp1,count+1});
                    mpp[temp1]=1;
                }
                 if(mpp.find(temp2)==mpp.end()&&dead.find(temp2)==dead.end()){
                    q.push({temp2,count+1});
                    mpp[temp2]=1;
                }
                
            }
        }
        return -1;
    }
};
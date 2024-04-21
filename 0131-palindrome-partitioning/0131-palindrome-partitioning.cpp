class Solution {
public:
    bool isPalindrome(int indx,int i,string s){
        int start=indx,end=i;
        while(start<=end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void solve(string s, int indx,vector<vector<string>>& ans,vector<string>& path){
        if(indx==s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=indx;i<s.size();i++){
            if(isPalindrome(indx,i,s)){
                path.push_back(s.substr(indx,i-indx+1));
                solve(s,i+1,ans,path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(s,0,ans,path);
        return ans;
    }
};
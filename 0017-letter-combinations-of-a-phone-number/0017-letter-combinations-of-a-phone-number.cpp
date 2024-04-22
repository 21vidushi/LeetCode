class Solution {
public:
    void solve(string digits,vector<string> &ans,string &res,int i,vector<string>&mpp){
        if(i>=digits.size()){
            if(res!="")
            ans.push_back(res);
            return;
        } 
        int n=digits[i]-'0';
        string val=mpp[n];
        for(int j=0;j<val.size();j++){
            res+=val[j];
            solve(digits,ans,res,i+1,mpp);
            res.pop_back();
            
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<string> mpp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string res="";
        solve(digits,ans,res,0,mpp);
        return ans;
    }
};
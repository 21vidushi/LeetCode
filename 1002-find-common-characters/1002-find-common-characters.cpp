class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> hash(26,0);
        for(int i=0;i<words[0].size();i++){
            hash[words[0][i]-'a']++;
        }
        for(int i=1;i<words.size();i++){
            vector<int> curr(26,0);
            for(int j=0;j<words[i].size();j++){
                curr[words[i][j]-'a']++;
            }
            for(int k=0;k<26;k++){
                hash[k]= min(hash[k],curr[k]);
            }
        }
        vector<string> ans;
        for(int i=0;i<26;i++){
            while(hash[i]!=0){
               ans.push_back(string(1, 'a' + i));
                hash[i]--;
            }
        }
        return ans;
    }
};
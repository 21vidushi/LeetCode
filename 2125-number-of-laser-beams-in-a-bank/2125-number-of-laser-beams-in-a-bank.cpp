class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0;
        vector<int> count1;
        for(int i=0;i<bank.size();i++){
            int count=0;
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1')  count++;
            }
            if(count>0) count1.push_back(count);
        }
        if(count1.size()<2)
            return 0;
        for(int i=0;i<count1.size()-1;i++){
            ans+=(count1[i]*count1[i+1]);
        }
        
        
        
       
        return ans;
    }
};
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(),greater<int>());
        long long ans=0;
        long long i=0,j=0;
        long long diff=0; 
        long long check=0;
        while(k!=0){
            if(happiness[i+j]-diff>=0){
            ans+=happiness[i+j]-diff;
                check++;
            }
            else {
                
                ans+=0;
            }
            diff++;
            j++;
            k--;
        }
        return ans;
    }
};
class Solution {
public:
    int minPatches(vector<int>& a, int n) {
        a.push_back(n);
        long long sum=0;
        long long cnt=0;
        for (int i=0;i<a.size();i++){
             while(a[i]-sum>1 && sum<n){
                sum+=(sum+1);
                cnt++;

             }
             if (sum>=n){
                break;
             }
             sum+=a[i];
             

        }
        return cnt;

        
    }
};
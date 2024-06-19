class Solution {
public: 
    bool check(vector<int>& bloomDay,int m,int k,int mid){
        int cnt=0,ans=0;
         for(int i=0;i<bloomDay.size();i++){
             if(bloomDay[i]<=mid){
                 cnt++;
             }
             else{
                  ans+=(cnt/k);
                  cnt=0;
             }
         }
         ans+=(cnt/k);
         if(ans>=m) return true;
         else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int ans=-1;
        int mini=*min_element(bloomDay.begin(),bloomDay.end());
        int maxi=*max_element(bloomDay.begin(),bloomDay.end());
        int low=mini,high=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(bloomDay,m,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
     return ans;
    }
};
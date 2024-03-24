class Solution {
public:
    bool place(vector<int>& position, int m, int k){
        int cnt=1,last=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-last>=k){
                last=position[i];
                cnt++;
            }
           if(cnt>=m) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int ans=0;
        sort(position.begin(),position.end());
        int maxi=*max_element(position.begin(),position.end());
        int mini=*min_element(position.begin(),position.end());
        int low=1,high=maxi-mini;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(place(position,m,mid)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        
        return ans;
    }
};
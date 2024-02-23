class Solution {
public:
    int countpair(vector<int>& nums,int l,int mid,int h){
        int cnt=0;
        int right=mid+1;
        for(int i=l;i<=mid;i++){
            while(right<=h&&nums[i]>(long long)2*nums[right]){
                right++;
            }
            cnt+=right-mid-1;
        }
        return cnt;
    }
    void merge(vector<int>&nums,int l,int mid,int h){
        vector<int> temp;
        int i=l,j=mid+1;
        while(i<=mid&&j<=h){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
                i++;
        }
         while(j<=h){
            temp.push_back(nums[j]);
                j++;
        }
      for(int i=l;i<=h;i++){
          nums[i]=temp[i-l];
      }
    }
    int mergeSort(vector<int>&nums,int l,int h){
        int cnt=0;
        if(l>=h) return cnt;
        int mid=(l+h)/2;
        cnt+=mergeSort(nums,l,mid);
        cnt+=mergeSort(nums,mid+1,h);
        cnt+=countpair(nums,l,mid,h);
        merge(nums,l,mid,h);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};
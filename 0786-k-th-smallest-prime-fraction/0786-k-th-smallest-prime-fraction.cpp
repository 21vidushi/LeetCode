class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        vector<pair<double,pair<int,int>>>v;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double frac=float(arr[i])/arr[j];
                v.push_back({frac,{arr[i],arr[j]}});
            }
        }
        sort(v.begin(),v.end());
        int a= v[k-1].second.first;
        int b=v[k-1].second.second;
        return {a,b};
    }
};
class Solution {
public:
    vector<int> nexts(vector<int>&arr,int n){
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            if(st.top()==-1||arr[i]>arr[st.top()]) ans[i]=st.top();
            else{
                while(st.top()!=-1&&arr[i]<=arr[st.top()]){
                    st.pop();
                }
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> prevs(vector<int>&arr,int n){
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for(int i=0;i<n;i++){
            if(st.top()==-1||arr[i]>arr[st.top()]) ans[i]=st.top();
            else{
                while(st.top()!=-1&&arr[i]<=arr[st.top()]){
                    st.pop();
                }
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int area=INT_MIN;
        vector<int> next= nexts(heights,n);
        vector<int> prev= prevs(heights,n);
        for(int i=0;i<heights.size();i++){
            int l=heights[i];
            if(next[i]==-1) next[i]=n;
            int w=next[i]-prev[i]-1;
            int newarea=l*w;
            area=max(area,newarea);
        }
        return area;
    }
};
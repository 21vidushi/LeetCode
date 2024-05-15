class Solution {
public:
    vector<int> nexts(vector<int>&h,int m){
        vector<int> ans(m);
        stack<int> st;
        st.push(-1);
        for(int i=m-1;i>=0;i--){
                while(st.top()!=-1&&h[st.top()]>=h[i]) st.pop();
                ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
     vector<int> prevs(vector<int>&h,int m){
        vector<int> ans(m);
        stack<int> st;
        st.push(-1);
        for(int i=0;i<m;i++){
                while(st.top()!=-1&&h[st.top()]>=h[i]) st.pop();
                ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int find(vector<int>&h,int m){
        int area=INT_MIN;
        vector<int> next(m),prev(m);
        next= nexts(h,m);
        prev=prevs(h,m);
        for(int i=0;i<m;i++){
            int l=h[i];
            if(next[i]==-1) next[i]=m;
            int b=next[i]-prev[i]-1;
            int newarea= l*b;
            area=max(area,newarea);
        }
        return area;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int area=0;
        int n=matrix.size(),m=matrix[0].size();
        vector<int> h(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0') h[j]=0;
                else h[j]+=1;
                
            }
            int newarea= find(h,m);
            area=max(area,newarea);
        }
        return area;
    }
};
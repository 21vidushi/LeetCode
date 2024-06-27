class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> e0,e1 ;
        e0 = edges[0] , e1 = edges[1];
        if(e0[0]==e1[0] || e0[0]==e1[1]){
            return e0[0];
        } 
        return e0[1];
    }
};

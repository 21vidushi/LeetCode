class Solution {
public:
    int passThePillow(int n, int time) {
          int totalpass=time/(n-1);
       int lastpass=time%(n-1);
       if(totalpass%2!=0){//last pass is reverse dir if odd
         return n-lastpass;
       }
       else return lastpass+1;
    }
};
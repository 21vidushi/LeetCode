class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int left=0,right=n-1;
        while(left<right){
            bool flag=false;
            if(s[left]==s[right]){
                while(s[left]==s[left+1]&&left+1<right){
                    flag=true;
                    left++;
                }
                while(s[right]==s[right-1]&&right-1>left){
                    flag=true;
                    right--;
                }
                if(flag==false){
                left++;
                right--;
                }
            }
            else break;
            
        }
        return right-left+1;
    }
};
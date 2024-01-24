class Solution {
public:
    int reverse(int n) {
        
        long long reverse=0; 
        
        while(n!=0)
        {
            int temp = n%10;
            reverse = reverse*10+temp;
            if(reverse>=INT_MAX || reverse<=INT_MIN)
			{ 
                return 0;
            }
            n/=10;
        }
        
        int ans=reverse;
        return ans;
    }
};
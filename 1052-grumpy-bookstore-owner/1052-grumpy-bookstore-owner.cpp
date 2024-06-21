class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int max_customers = 0, customer = 0, temp = 0, n = grumpy.size();
        for(int i = 0; i < n; i++){
            if(grumpy[i] == 0)
                customer += customers[i];
        }
        temp += customer;
        for(int j = 0; j < minutes; j++){
                if(grumpy[j] == 1)
                    temp += customers[j];
        }
        max_customers = temp;

        for(int i = minutes; i < n; i++){
            if(grumpy[i - minutes] == 1)
                temp -= customers[i - minutes];
            if(grumpy[i] == 1)
                temp += customers[i];

            max_customers = max(max_customers, temp);
        }
        cout<< customer << endl;
        return max_customers;
    }
};
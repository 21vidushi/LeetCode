class DataStream {
public:
    int value,k,ct;
    DataStream(int value, int k) {
         this->value=value;
        this->k=k;
         ct=0;
    }
    
    bool consec(int num) {
        if(num==value) ct++;
        else{ ct=0; return false;}
        if(ct>=k) return true;
        return false;
    }
};
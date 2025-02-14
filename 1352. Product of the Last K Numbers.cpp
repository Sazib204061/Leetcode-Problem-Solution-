class ProductOfNumbers {
public:
    vector<int>ar, zero, mul;
    ProductOfNumbers() {
        ar.clear();
        zero.clear();
        mul.clear();

    }
    
    void add(int num) {
        if(num==0)
        {
            if(ar.size()==0)
            {
                ar.push_back(0);
                zero.push_back(1);
                mul.push_back(1);
            }
            else
            {
                int previous_index = ar.size()-1;
                ar.push_back(num);
                zero.push_back(zero[previous_index]+1);
                mul.push_back(1);
            }
        }
        else
        {
            if(ar.size()==0)
            {
                ar.push_back(num);
                zero.push_back(0);
                mul.push_back(num);
            }
            else{
                int previous_index = ar.size()-1;
                ar.push_back(num);
                zero.push_back(zero[previous_index]);
                mul.push_back(mul[previous_index]*num);
            }
        }
    }
    
    int getProduct(int k) {
        int r = ar.size()-1;
        int l = r-(k-1);
        int zero_cnt = zero[r]-zero[l];

        if(zero_cnt>0)return 0;

        int m = (mul[r]/mul[l])* ar[l];

        return m;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

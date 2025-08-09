class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        double x = log2(n);
        int y = (int)x;
        double z= (double)y;
        if(x==z)return true;
        return false;
    }
};
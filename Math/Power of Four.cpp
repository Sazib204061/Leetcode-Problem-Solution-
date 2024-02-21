class Solution {
public:
    bool isPowerOfFour(int n) {
        return !((log10(n)/log10(4))-floor((log10(n)/log10(4))));
    }

    /*
    help form : 
    https://www.techiedelight.com/check-given-number-power-of-4/
    */
};

class Solution {
public:

    int minimizeXor(int num1, int num2) {
        int bit2 = __builtin_popcount(num2);

        int bit1 = __builtin_popcount(num1);
        int x = num1;
        if(bit1==bit2)return num1;
        else if(bit1>bit2)
        {
            int ind = 0;
            while(ind<32)
            {
                if(bit1==bit2)
                {
                    return x;
                }
                int val = 1<<ind;
                if(x&val)
                {
                    x = x^val;
                    bit1--;
                }
                ind++;
            }
        }
        else
        {
            int ind = 0;
            while(ind<32)
            {
                if(bit1==bit2)
                {
                    return x;
                }
                int val = 1<<ind;
                if(!(x&val))
                {
                    x = x^val;
                    bit1++;
                }
                ind++;
            }
        }

        return 0;

    }
};

class Solution {
public:
    /*int dsum(int n)
    {
        int sum = 0;
        while(n>0)
        {
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int addDigits(int n) {
        int sum = 0;
        while(1)
        {
            sum = dsum(n);
            if(sum<10)
            {
                return sum;
            }
            else n = sum;
        }
    }*/
    /*
    We can find regular pattern by enumerate following case:
    1=1; 2=2; 3=3; 4=4; 5=5; 6=6; 7=7; 8=8; 9=9;
    10=1; 11=2; 12=3; 13=4; 14=5; 15=6; 16=7; 17=8; 18=9;
    19=1; 20=2; 21=3; 22=4; 23=5; 24=6; 25=7; 26=8; 27=9;
    ... ...
    so, we supposed that the rule is a cycle per 9 number.
    the math formulation:
    (num - 1) % 9 + 1
    */



    int addDigits(int n) {
        return (n-1)%9+1;
    }
};


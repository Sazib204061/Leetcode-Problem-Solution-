class Solution {
public:
    long long flowerGame(int n, int m) {
        /*long long no, ne, mo, me;
        if(n&1)
        {
            no = (n/2)+1;
            ne = n/2;
        }
        else
        {
            no = n/2;
            ne = n/2;
        }
        if(m&1)
        {
            mo = (m/2)+1;
            me = m/2;
        }
        else
        {
            mo = m/2;
            me = m/2;
        }
        return (no*me+mo*ne);
        */
        return m*1LL*n/2;
    }
};
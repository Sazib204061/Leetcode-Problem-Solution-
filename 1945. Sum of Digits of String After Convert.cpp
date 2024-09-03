class Solution {
public:
    int d_sum(int n)
    {
        int sum = 0;
        while(n>0)
        {
            int rem = n%10;
            n/=10;
            sum+=rem;
        }
        return sum;
    }
    int getLucky(string s, int k) {
        int sum = 0;
        string ss = "";
        for(int i = 0; i<s.size(); i++)
        {
            int x = s[i]-'a'+1;
            string p = to_string(x);
            ss+=p;
        }
        for(int i = 0; i<ss.size(); i++)
        {
            sum+=ss[i]-'0';
        }
        k--;
        for(int i = 0; i<k; i++)
        {
            sum = d_sum(sum);
        }
        return sum;
    }
};

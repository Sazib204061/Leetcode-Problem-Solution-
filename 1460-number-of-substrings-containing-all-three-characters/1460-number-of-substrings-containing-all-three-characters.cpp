class Solution {
public:
    bool abc_at_least_one(int a, int b, int c)
    {
        if(a>0 && b>0 && c>0)return true;
        return false;
    }
    int numberOfSubstrings(string s) {
        int n = s.size(), L = 0, R = 0, a = 0, b = 0, c = 0, ans = 0;
        while(R<n)
        {
            if(s[R]=='a')a++;
            else if(s[R]=='b')b++;
            else c++;
            while(abc_at_least_one(a, b, c))
            {
                ans+=n-R;
                if(s[L]=='a')a--;
                else if(s[L]=='b')b--;
                else c--;
                L++;
            }
            R++;
        }

        return ans;
    }
};
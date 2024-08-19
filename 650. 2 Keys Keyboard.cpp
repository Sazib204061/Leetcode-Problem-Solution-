#define fast ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
class Solution {
public:
    int nn;
    int dp[1005][1005];
    int f(int sz, int copy)
    {
        if(sz==nn)
        {
            return 0;
        }
        else if(sz>nn)return 100000;

        if(dp[sz][copy]!=-1)return dp[sz][copy];

        int ans1 = 2 + f(sz*2, sz);  //copy and past
        int ans2 = 1 + f(sz+copy, copy);  //only past

        return dp[sz][copy] = min(ans1, ans2); 
    }
    int minSteps(int n) {
        fast;
        nn = n;
        memset(dp, -1, sizeof(dp));
        if(n==1)return 0;
        else
        {
            return 1+f(1,1);
        }
    }
};

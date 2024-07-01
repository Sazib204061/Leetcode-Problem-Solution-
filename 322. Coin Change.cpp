class Solution {
public:
    int dp[13][10005];
    int n;
    int inf = 1000000000;
    int f(int ind, int sum, int amount, vector<int>&coins)
    {
        if(ind==n)
        {
            if(sum==amount)return 0;
            else return inf;
        }
        if(sum==amount)return 0;

        if(sum>amount)return inf;

        if(dp[ind][sum]!=-1)return dp[ind][sum];
        
        int ans1 = 0, ans2 = 0;
        ans1 = ans1+f(ind+1, sum, amount, coins);

        if(coins[ind]<=amount)
            ans2 = ans2+f(ind, sum+coins[ind], amount, coins)+1;
        else return inf;
        
        return dp[ind][sum]=min(ans1, ans2);

    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        sort(coins.begin(), coins.end());
        n = coins.size();
        if(amount==0)return 0;
        int ans = f(0, 0, amount, coins);
        //cout<<ans<<endl;
        if(ans==inf)return -1;
        else return ans;        
    }
};

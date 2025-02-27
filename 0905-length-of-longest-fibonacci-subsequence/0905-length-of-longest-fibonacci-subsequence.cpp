class Solution {
public:
    unordered_map<int,int>mp;
    int dp[1001][1001];
    int ans = 0;
    int f(int ci, int bi, vector<int>&arr)
    {
        if(dp[ci][bi]!=-1)return dp[ci][bi];
        int c = arr[ci], b = arr[bi];
        int a = c-b;
        int len = 2;
        if(a>=b)return dp[ci][bi] = len;
        
        if(mp.count(a))
        {
            int ind_a = mp[a];
            len = f(bi, ind_a, arr)+1;
            ans = max(ans, len);
        }
        return dp[ci][bi] = len;

    }



    int lenLongestFibSubseq(vector<int>& arr) {
        mp.clear();
        memset(dp, -1, sizeof(dp));
        int n = arr.size();
        for(int i = 0; i<n; i++)
        {
            mp[arr[i]] = i;
        }
        //A[i] = A[i-2] + A[i-1] 
        //a, b, c .....
        

        for(int bi = 1; bi<n-1; bi++)
        {
            for(int ci = bi+1; ci<n; ci++)
            {
                f(ci, bi, arr);
            }
        }

        return ans;
        
    }
};
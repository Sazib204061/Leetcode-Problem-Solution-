class Solution {
public:
    
    int countLargestGroup(int n) {
        unordered_map<int,int>mp;
        int mx = 0;
        for(int i = 1; i<=n; i++)
        {
            int nn = i, sum = 0;
            while(nn)
            {
                sum+=(nn%10);
                nn/=10;
            }
            mp[sum]++;
            mx = max(mx, mp[sum]);
        }
        int ans = 0;
        for(auto it : mp)
        {
            if(it.second==mx)ans++;
        }
        return ans;
    }
};
#define fast ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);

class Solution {
public:
    int findTheLongestSubstring(string s) {
        fast;
        int n = s.size(), mask = 0, ans = 0;
        unordered_map<int,int>mp;   //{mask, first indext of this mask find}
        mp[0] = -1;
        for(int i = 0; i<n; i++)
        {
            if(s[i]=='a')
            {
                mask^=(1<<0);
            }
            else if(s[i]=='e')
            {
                mask^=(1<<1);
            }
            else if(s[i]=='i')
            {
                mask^=(1<<2);
            }
            else if(s[i]=='o')
            {
                mask^=(1<<3);
            }
            else if(s[i]=='u')
            {
                mask^=(1<<4);
            }

            if(mp.find(mask)!=mp.end())
            {
                ans = max(ans, i-mp[mask]);
            }
            else
            {
                mp[mask] = i;
            }
        }
        return ans;
    }
};

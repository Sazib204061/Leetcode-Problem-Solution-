class Solution {
public:
    bool canArrange(vector<int>& ar, int k) {
        int n = ar.size();
        map<int,int>mp;
        for(int i = 0; i<n; i++)
        {
            ar[i] = (ar[i]%k+k)%k;
            mp[ar[i]]++;
        }

        for(auto it : mp)
        {
            int x = it.first;
            int y = (k-x)%k;

            if(x==y)
            {
                if(it.second%2!=0)
                {
                    return false;
                }
            }

            if(it.second!=mp[y])return false;

        }

        return true;
    }
};

#define lli long long int
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        lli n = folder.size();
        vector<pair<int, string>>v;
        for(lli i = 0; i<n; i++)
        {
            v.push_back({folder[i].size(), folder[i]});
        }
        sort(v.begin(), v.end());

        folder.clear();

        for(auto it : v)
        {
            folder.push_back(it.second);
        }


        
        map<string,int>mp;
        mp[folder[0]] = 1;
        vector<string>ans;
        ans.push_back(folder[0]);

        for(lli i = 1; i<n; i++)
        {
            string ss = "";
            lli f = 0;
            for(lli j = 0; j<folder[i].size(); j++)
            {
                if(folder[i][j]=='/')
                {
                    if(mp[ss]==1)
                    {
                        f = 1;
                        break;
                    }
                }
                ss+=folder[i][j];
            }

            if(f==0)
            {
                mp[ss] = 1;
                ans.push_back(ss);
            }
        }
        return ans;
    }
};

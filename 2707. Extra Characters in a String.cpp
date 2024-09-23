class Solution {
public:
    unordered_map<string,int>ump;
    int dp[55];
    int f(string &s, int ind)
    {
        if(ind>=s.size())return 0;

        if(dp[ind]!=-1)return dp[ind];

        int extra = INT_MAX;
        string temp = "";

        for(int i = ind; i<s.size(); i++)
        {
            temp+=s[i];

            if(ump.find(temp)!=ump.end())
            {
                extra = min(extra, f(s, i+1));
            }
        }

        extra = min(extra, 1+f(s, ind+1));

        return dp[ind] = extra;
    }
    

    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i<dictionary.size(); i++)
        {
            ump[dictionary[i]]++;
        }
        return f(s,0);
    }
};

//Problem Link: https://leetcode.com/problems/valid-parenthesis-string/description/?envType=list&envId=oiap2cwh
class Solution {
public:
    bool f(int ind, int opb, string &s, vector<vector<int>>&dp)
    {
        if(ind==s.size())return opb==0;
        if(dp[ind][opb]!=-1)return dp[ind][opb];

        bool ans = false;
        if(s[ind]=='*')
        {
            ans|=f(ind+1, opb+1, s, dp);
            if(opb)ans|=f(ind+1, opb-1, s, dp);
            ans|=f(ind+1, opb, s, dp);
        }
        else
        {
            if(s[ind]=='(')
            {
                ans=f(ind+1, opb+1, s, dp);
            }
            else if(opb) ans = f(ind+1, opb-1, s, dp);
        }
        return dp[ind][opb] = ans;
    }
    bool checkValidString(string s)
    {
        vector<vector<int>>dp(200, vector<int>(200,-1));
        return f(0,0,s, dp);
    }
};

/*
*/

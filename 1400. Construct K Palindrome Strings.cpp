class Solution {
public:
    bool is_possible_to_constract_palindram(string &s, int k)
    {
        map<char,int>mp;
        int n = s.size();
        for(int i = 0; i<n; i++)
        {
            mp[s[i]]++;
        }
        int odd = 0;
        for(auto it : mp)
        {
            if(it.second & 1)
            {
                odd++;
            }
        }

        if(odd<=k)
        {
            return true;
        }

        return false;
    }
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(n<k)return false;
        return is_possible_to_constract_palindram(s, k);
    }
};

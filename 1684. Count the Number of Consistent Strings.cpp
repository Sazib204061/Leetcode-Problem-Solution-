class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char,int>mp;
        for(int i = 0; i<allowed.size(); i++)
        {
            mp[allowed[i]]++;
        }
        int ans = 0;
        for(int i = 0; i<words.size(); i++)
        {
            int f = 0;
            for(int j = 0; j<words[i].size(); j++)
            {
                if(!mp[words[i][j]])
                {
                    f = 1;
                }
            }
            if(f==0)ans++;
        }
        return ans;
    }
};

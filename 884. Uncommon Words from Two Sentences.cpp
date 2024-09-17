class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>ans;
        map<string, int>mp;
        string str = "";
        for(int i = 0; i<s1.size(); i++)
        {
            if(i==s1.size()-1)
            {
                str+=s1[i];
                mp[str]++;
                break;
            }

            else if(s1[i]==' ')
            {
                mp[str]++;
                str = "";
            }
            else str+=s1[i];
        }
        str = "";
        for(int i = 0; i<s2.size(); i++)
        {
            if(i==s2.size()-1)
            {
                str+=s2[i];
                mp[str]++;
                break;
            }
            else if(s2[i]==' ')
            {
                mp[str]++;
                str = "";
            }
            else str+=s2[i];
        }

        for(auto it : mp)
        {
            if(it.second==1)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

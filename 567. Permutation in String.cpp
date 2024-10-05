class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;

        vector<int>ar(26,0), ar2(26,0);
        for(int i = 0; i<s1.size(); i++)
        {
            ar[s1[i]-'a']++;
        }

        for(int i = 0; i<s1.size(); i++)
        {
            ar2[s2[i]-'a']++;
        }

        int f = 0;
        for(int i = 0; i<26; i++)
        {
            if(ar[i]!=ar2[i])
            {
                f = 1;
                break;
            }
        }
        if(f==0)return true;

        int l = 0, r = s1.size()-1;
        while(r<s2.size())
        {
            ar2[s2[l]-'a']--;
            l++;
            r++;
            if(r<s2.size())
            {
                ar2[s2[r]-'a']++;
                f = 0;
                for(int i = 0; i<26; i++)
                {
                    if(ar[i]!=ar2[i])
                    {
                        f = 1;
                        break;
                    }
                }
                if(f==0)return true;
            }
        }

        return false;

    }
};

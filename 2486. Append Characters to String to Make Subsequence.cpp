#define fast ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
class Solution {
public:
    int appendCharacters(string s, string t) {
        fast;
        int n = s.size(), m = t.size(), j = 0;
        for(int i = 0; i<m; i++)
        {
            while(1)
            {
                if(t[i]==s[j])
                {
                    j++;
                    break;
                }
                j++;
                if(j>=n)
                {
                    return m-i;
                }
            }
        }
        return 0;
    }
};

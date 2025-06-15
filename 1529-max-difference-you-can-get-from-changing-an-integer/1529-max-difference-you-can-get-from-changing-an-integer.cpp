class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string s1 = s, s2 = s;

        for(int i = 0; i<s1.size(); i++)
        {
            if(s1[i]!='9')
            {
                int j = i;
                char ch = s1[i];
                while(j<s1.size())
                {
                    if(s1[j]==ch)
                    {
                        s1[j] = '9';
                    }
                    j++;
                }
                break;
            }

        }

        for(int i = 0; i<s2.size(); i++)
        {
            if(s2[i]>'1')
            {
                int j = i;
                char ch = s2[i];
                while(j<s2.size())
                {
                    if(i==0 && s2[j]==ch)
                    {
                        s2[j] = '1';
                    }
                    else if(s2[j]==ch)
                    {
                        s2[j] = '0';
                    }
                    j++;
                }
                break;
            }

        }

        int mx = stoi(s1), mn = stoi(s2);
        return mx-mn;
    }
};
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        string str = "";
        for(int i = 0; i<s.size();i++)
        {
            str+=s[i];
            if((i+1)%k==0)
            {
                ans.push_back(str);
                str = "";
            }

        }
        while(str.size()%k!=0)
        {
            str+=fill;
        }
        if(str.size()>0)
        {
            ans.push_back(str);
        }
        return ans;
    }
};
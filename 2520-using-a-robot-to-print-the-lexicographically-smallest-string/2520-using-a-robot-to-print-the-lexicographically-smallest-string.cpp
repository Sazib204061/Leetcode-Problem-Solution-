class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        string ans = "";
        stack<char>stk;
        map<char,int>fre;
        for(int i = 0; i<n; i++)
        {
            fre[s[i]]++;
        }
        char curr_min = 'a';
        for(int i = 0; i<n; i++)
        {
            while(fre[curr_min]<1)
            {
                curr_min++;
                if(curr_min>'z')break;
            }

            fre[s[i]]--;

            while(!stk.empty() && stk.top()<=curr_min)
            {
                ans+=stk.top();
                stk.pop();
            }

            if(s[i]==curr_min)
            {
                ans+=s[i];
            }
            else
            {
                stk.push(s[i]);
            }
            
        }

        while(!stk.empty())
        {
            ans+=stk.top();
            stk.pop();
        }
        return ans;
    }
};
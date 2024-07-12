#define fast ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
class Solution {
public:
    int cal_ab(string &s, int x, int y)
    {
        int points = 0;
        stack<char>st;
        int n = s.size();
        for(int i = 0; i<n; i++)
        {
            if(st.empty() || s[i]=='a')
            {
                st.push(s[i]);
            }
            else if(s[i]=='b')
            {
                if(st.empty())st.push(s[i]);
                else if(st.top()=='a')
                {
                    points+=x;
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        int a = 0, b = 0;
        while(!st.empty())
        {
            if(st.top()=='a')a++;
            else b++;
            st.pop();
        }
        points+=(min(a,b)*y);

        return points;

    }
    int cal_ba(string &s, int x, int y)
    {
        int points = 0;
        stack<char>st;
        int n = s.size();
        for(int i = 0; i<n; i++)
        {
            if(st.empty() || s[i]=='b')
            {
                st.push(s[i]);
            }
            else if(s[i]=='a')
            {
                if(st.empty())st.push(s[i]);
                else if(st.top()=='b')
                {
                    points+=y;
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        int a = 0, b = 0;
        while(!st.empty())
        {
            if(st.top()=='a')a++;
            else b++;
            st.pop();
        }
        points+=(min(a,b)*x);

        return points;

    }
    int maximumGain(string s, int x, int y) {
        fast;
        int n = s.size(), ans = 0;
        string ss = "";
        for(int i = 0; i<n; i++)
        {
            if(s[i]=='a'||s[i]=='b')
            {
                ss+=s[i];
                if(i==n-1)
                {
                    int p = cal_ab(ss, x, y);
                    int q = cal_ba(ss, x, y);
                    ans+=max(p,q);
                }
            }
            else
            {
                int p = cal_ab(ss, x, y);
                int q = cal_ba(ss, x, y);
                ans+=max(p,q);
                ss = "";
            }
        }
        return ans;

    }
};

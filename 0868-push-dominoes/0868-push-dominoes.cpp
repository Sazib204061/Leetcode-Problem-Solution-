class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string ans = "";
        stack<char>st;
        int L = 0, R = 0;
        for(int i = 0; i<n; i++)
        {
            if(dominoes[i]=='.')
            {
                st.push(dominoes[i]);
            }
            else if(dominoes[i]=='R')
            {

                if(R==1)
                {
                    while(!st.empty())
                    {
                        ans+='R';
                        st.pop();
                    }
                }
                else
                {
                    while(!st.empty())
                    {
                        ans+='.';
                        st.pop();
                    }
                }
                R = 1;
                ans+='R';
            }
            else
            {
                if(R==1)
                {
                    int nn = st.size();
                    int x = nn/2;
                    if(nn&1)
                    {
                        for(int j = 0; j<x; j++)
                        {
                            ans+='R';
                        }
                        ans+='.';
                        for(int j = 0; j<x; j++)
                        {
                            ans+='L';
                        }
                    }
                    else
                    {
                        for(int j = 0; j<x; j++)
                        {
                            ans+='R';
                        }
                        for(int j = 0; j<x; j++)
                        {
                            ans+='L';
                        }
                    }
                    while(!st.empty())
                    {
                        st.pop();
                    }
                }
                else
                {
                    while(!st.empty())
                    {
                        ans+='L';
                        st.pop();
                    }
                }
                ans+='L';
                R = 0;
            }
        }

        if(st.size()>0)
        {
            if(R==1)
            {
                while(!st.empty())
                {
                    ans+='R';
                    st.pop();
                }
            }
            else
            {
                while(!st.empty())
                {
                    ans+='.';
                    st.pop();
                }
            }
        }

        return ans;
    }
};
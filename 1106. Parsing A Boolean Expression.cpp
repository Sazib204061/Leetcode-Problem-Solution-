class Solution {
public:
    bool parseBoolExpr(string exp) {
        // string temp = "(";
        // temp+=exp;
        // temp+=")";
        // exp = temp;
        int n = exp.size();
        int f_cnt = 0, t_cnt = 0;
        stack<char>st;
        for(int i = 0; i<n; i++)
        {
            if(exp[i]=='(')continue;
            if(exp[i]==',')continue;

            if(st.empty())
            {
                st.push(exp[i]);
            }
            else if(exp[i]==')')
            {
                t_cnt = 0;
                f_cnt = 0;

                while(1)
                {
                    if(st.top()=='&')
                    {
                        st.pop();
                        if(f_cnt==0)
                        {
                            st.push('t');
                        }
                        else st.push('f');
                        break;
                    }
                    else if(st.top()=='|')
                    {
                        st.pop();
                        if(t_cnt>=1)
                        {
                            st.push('t');
                        }
                        else st.push('f');
                        break;
                    }
                    else if(st.top()=='!')
                    {
                        st.pop();
                        if(t_cnt>0)
                        {
                            st.push('f');
                        }
                        else st.push('t');
                        break;
                    }
                    else if(st.top()=='t')
                    {
                        st.pop();
                        t_cnt++;
                    }
                    else
                    {
                        st.pop();
                        f_cnt++;
                    }
                }
            }
            else st.push(exp[i]);
        }
        if(st.top()=='t')return true;
        else return false;
        //return st.top();
    }
};

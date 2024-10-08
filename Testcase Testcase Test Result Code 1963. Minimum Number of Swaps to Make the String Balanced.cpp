class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(int i = 0; i<s.size(); i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else if(s[i]==']')
            {
                if(st.top()=='[')
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        int x = st.size()/2;
        if(x%2==0)
        {
            return x/2;
        }
        else
        {
            return x/2+1;
        }
    }
};

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n&1)return false;

        for(int i = 0; i<n; i++)
        {
            if(locked[i]=='0')
            {
                s[i] = '0';
            }
        }

        stack<int>first_br, zero;
        for(int i = 0; i<n; i++)
        {
            if(s[i]==')')
            {
                if(!first_br.empty())
                {
                    first_br.pop();
                }
                else if(!zero.empty())
                {
                    zero.pop();
                }
                else return false;
            }
            else if(s[i]=='0')
            {
                zero.push(i);
            }
            else first_br.push(i);
        }
        while(!first_br.empty() && !zero.empty())
        {
            if(first_br.top()>zero.top())
            {
                return false;
            }
            else
            {
                first_br.pop();
                zero.pop();
            }
        }

        if(first_br.empty())return true;
        return false;
    }
};


/* 

(0)0)(000)000(00(0)(000000((00)0)00(0)

*/

class Solution {
public:
    
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>st;
        for(int i = 0; i<n; i++)
        {
            if(st.empty())
            {
                st.push(asteroids[i]);
            }
            else if(asteroids[i]>0)
            {
                st.push(asteroids[i]);
            }
            else
            {
                while(1)
                {
                    if(st.empty())
                    {
                        st.push(asteroids[i]);
                        break;
                    }
                    int x = st.top();
                
                    if(x<0)
                    {
                        st.push(asteroids[i]);
                        break;
                    }
                    if(x>abs(asteroids[i]))
                    {
                        break;
                    }
                    else if(x==abs(asteroids[i]))
                    {
                        st.pop();
                        break;
                    }
                    else
                    {
                        st.pop();
                    }

                }
            }
        }

        vector<int>ans;

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};

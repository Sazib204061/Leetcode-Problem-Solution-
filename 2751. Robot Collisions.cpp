class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        map<int,int>mp2;
        map<int,pair<int,char>>mp;
        vector<int>ans;
        int n = positions.size();
        for(int i = 0; i<n; i++)
        {
            mp[positions[i]] = {healths[i], directions[i]};
        }
        stack<pair<int,pair<int,char>>>st;
        for(auto it : mp)
        {
            int no = it.first, h = it.second.first;
            char d = it.second.second;
            //cout<<no<<" "<<h<<" "<<d<<endl;
            if(st.empty() || d=='R')
            {
                st.push({no,{h,d}});
            }
            else
            {
                int f = 0;
                while(!st.empty()){
                    auto it2 = st.top();
                    int no2 = it2.first, h2 = it2.second.first;
                    char d2 = it2.second.second;
                    st.pop();
                    
                    if(d2=='L')
                    {
                        st.push({no2, {h2, d2}});
                        st.push({no, {h, d}});
                        break;
                    }

                    if(h2==h)
                    {
                        f = 1;
                        break;                       
                    }
                    else if(h2>h)
                    {
                        h2--;
                        st.push({no2, {h2, d2}});
                        break;
                    }
                    else
                    {
                        h--;
                    }
                    
                }

                if(st.empty() && f==0)
                {
                    st.push({no, {h, d}});
                }

            }
        }

        while(!st.empty())
        {
            auto it = st.top();
            int no = it.first, h = it.second.first;
            char d = it.second.second;
            mp2[no] = h;
            st.pop();
        }

        for(int i = 0; i<n; i++)
        {
            if(mp2[positions[i]]>0)
            {
                ans.push_back(mp2[positions[i]]);
            }
        }

        return ans;
    }
};

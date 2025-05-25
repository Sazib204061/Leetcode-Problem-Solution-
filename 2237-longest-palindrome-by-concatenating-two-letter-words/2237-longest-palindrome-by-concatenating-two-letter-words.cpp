class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        int ans = 0, mx = 0;
        for(int i = 0; i<words.size(); i++)
        {
            mp[words[i]]++;
        }

        for(int i = 0; i<words.size(); i++)
        {
            if(mp[words[i]]<=0)continue;
            string s = words[i];
            reverse(s.begin(), s.end());

            //cout<<words[i]<<" "<<s<<endl;

            if(s==words[i])
            {
                if(mp[s]>1)
                {
                    //cout<<i<<endl;
                    ans+=(s.size()*2);
                }
                else
                {
                    mx = max(mx, (int)s.size());
                }
                mp[s]--;
            }
            else if(mp[s]>0)
            {
                //cout<<"-"<<i<<endl;
                ans+=(s.size()*2);
                mp[s]--;
            }
            
            mp[words[i]]--;
        }
        return ans+mx;
    }
};

/*
["xx","lx","bx","lb","lb","bb","bx","lb"]
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(),fre[500] = {0}, ans = 1;
        if(n==0)return 0;

        for(int i = 0, j = 0; i<n;)
        {
            if(fre[s[i]]==0)
            {
                //cout<<"fr "<<fre[s[i]]<<endl;
                ans = max(ans, (i-j)+1);
                //cout<<ans<<" i = "<<i<<" j = "<<j<<endl;
                fre[s[i]]++;
                i++;

            }
            else
            {
                //cout<<"fr "<<fre[s[i]]<<endl;
                //cout<<ans<<" si = "<<i<<" j = "<<j<<endl;
                fre[s[i]]++;
                while(j<i)
                {
                    if(s[i]==s[j])
                    {
                        
                        fre[s[j]]--;
                        j++;
                        break;
                    }
                    
                    fre[s[j]]--;
                    j++;
                }
                i++;

                //cout<<ans<<" sei = "<<i<<" j = "<<j<<endl;
            }
        }
        return ans;
    }
};
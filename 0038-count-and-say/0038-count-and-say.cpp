class Solution {
public:
    vector<string>ar;
    void cal()
    {
        ar.push_back("1");

        for(int i = 1; i<=30; i++)
        {
            string s = ar[i-1], ans = "", sub = "";
            sub+=s[0];
            int occ = 0;
            for(int j = 1; j<s.size(); j++)
            {
                //cout<<sub<<endl;
                if(s[j]==sub[0])
                {
                    sub+=s[j];
                }
                else
                {
                    occ = sub.size();
                    ans+=to_string(occ)+sub[0];
                    sub = "";
                    sub += s[j];
                    //cout<<"ans = "<<ans<<endl;
                }
            }

            occ = sub.size();
            ans+=to_string(occ)+sub[0];
            sub = "";
            ar.push_back(ans);
        }
    }
    string countAndSay(int n) {
        cal();
        return ar[n-1];
    }
};
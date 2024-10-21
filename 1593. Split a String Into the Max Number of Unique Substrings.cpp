class Solution {
public:
    int f(int st, string &s, unordered_map<string, int>&ump)
    {
        if(st==s.size())return 0;   //base case;

        int ans = 0;
        for(int ed = st+1; ed<=s.size(); ed++)
        {
            string sub_str = s.substr(st, ed-st);
            //cout<<sub_str<<" ";
            if(ump[sub_str]<1)
            {
                ump[sub_str]++;
                ans = max(ans, 1+f(ed, s, ump));
                ump[sub_str]--;
            }
        }
        return ans;
    }
    int maxUniqueSplit(string s) {
        unordered_map<string, int>ump;
        return f(0, s, ump);
    }
};

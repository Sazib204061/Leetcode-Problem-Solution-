class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size(), ch = -1;
        string ans = "";

        for(int i = 0; i<n-2; i++)
        {
            if(num[i]==num[i+1] && num[i]==num[i+2] && (num[i]-'0')>ch)
            {
                ch = num[i]-'0';
                ans="";
                ans += num[i];
                ans += num[i];
                ans += num[i];
            }
        }
        return ans;
    }
};
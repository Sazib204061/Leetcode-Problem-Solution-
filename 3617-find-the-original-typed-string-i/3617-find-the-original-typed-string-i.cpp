class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;
        int i = 0, n = word.size();
        
        while(i<n)
        {
            int cnt = 0;
            char prev = word[i];
            while(i<n && word[i]==prev)
            {
                i++;
                cnt++;
            }
            ans+=(cnt-1);

        }
        return ans;
    }
};
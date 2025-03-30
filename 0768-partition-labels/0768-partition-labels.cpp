class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int>lastOccuranceIndex;
        int n = s.size();
        for(int i = 0; i<n; i++)
        {
            lastOccuranceIndex[s[i]] = i;
        }
        int L = 0, R = lastOccuranceIndex[s[L]], startIndex = 0;
        vector<int>ans;
        while(1)
        {
            if(R==n-1)
            {
                ans.push_back(R-startIndex+1);
                return ans;
            }
            if(L==R)
            {
                ans.push_back(R-startIndex+1);
                L = R+1;
                R = lastOccuranceIndex[s[L]];
                startIndex = L;
            }
            else
            {
                R = max(R, lastOccuranceIndex[s[L]]);
                L++;
            }

        }

        return ans;

    }
};
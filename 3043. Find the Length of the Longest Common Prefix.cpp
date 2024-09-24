class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int>mp;
        for(int i = 0; i<arr2.size(); i++)
        {
            string x = to_string(arr2[i]);
            string s = "";
            for(int j = 0; j<x.size(); j++)
            {
                s+=x[j];
                mp[s]++;
            }
        }
        int ans = 0;
        for(int i = 0; i<arr1.size(); i++)
        {
            string x = to_string(arr1[i]);
            string s = "";
            for(int j = 0; j<x.size(); j++)
            {
                s+=x[j];
                if(mp[s])
                {
                    ans = max(ans, (int)s.size());
                }
            }
        }
        return ans;
    }
};

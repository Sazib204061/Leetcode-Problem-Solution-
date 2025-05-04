class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int>mp;
        for(int i = 0; i<dominoes.size(); i++)
        {
            vector<int>ar = dominoes[i];
            sort(ar.begin(), ar.end());
            //cout<<ar[0]<<endl;
            mp[{ar[0], ar[1]}]++;
        }
        int ans = 0;
        for(auto it : mp)
        {
            int n = it.second-1;
            //cout<<n<<endl;
            ans += ((n*(n+1))/2);
        }
        return ans;
    }
};
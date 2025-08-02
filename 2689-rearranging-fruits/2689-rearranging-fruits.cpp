#define ll long long
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<ll, ll>mp;
        int n = basket1.size(), mn = 10000000000;
        for(ll i = 0; i<n; i++)
        {
            mn = min(mn, min(basket1[i], basket2[i]));
            mp[basket1[i]]++;  //increase frequency
            mp[basket2[i]]--;  //remove duplicate frequency and negatively increase frequency which is taken by using absulot value.
        }
        vector<int>merge;
        for(auto it : mp)
        {
            if((abs(it.second) & 1))
            {
                return -1;
            }
            else
            {
                for(ll i = 0; i<abs(it.second)/2; i++)
                {
                    merge.push_back(it.first);
                }
            }
        }
        ll cost = 0;
        sort(merge.begin(), merge.end());
        for(ll i = 0; i<merge.size()/2; i++)
        {
            cost+=min(merge[i], 2*mn);
        }
        return cost;       

    }
};

/*

[80,43,80,88,43,100,88]

[32,32,42,68,68,100,42]

[5,1,4] mn = 1
[4,5,1]

*/
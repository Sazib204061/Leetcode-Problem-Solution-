class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int,int>mx;
        for(int i = 0; i<items.size(); i++)
        {
            int x = mx[items[i][0]];
            mx[items[i][0]] = max(items[i][1], x);
        }
        int mx_val = 0;
        for(auto it : mx)
        {
            //cout<<it.first<<" "<<it.second<<" "<<mx_val<<endl;
            mx_val = max(it.second, mx_val);
            mx[it.first] = mx_val;
        }
        vector<pair<int,int>>ar;
        for(auto it : mx)
        {
            ar.push_back({it.first, it.second});
        }

        // for(auto it : ar)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }

        vector<int>ans;

        for(int i = 0; i<queries.size(); i++)
        {
            int l = 0, r = ar.size()-1, mxi = 0;
            while(l<=r)
            {
                int mid = (l+r)/2;
                if(ar[mid].first>queries[i])
                {
                    r = mid-1;
                }
                else
                {
                    mxi = max(mxi, ar[mid].second);
                    l = mid+1;
                }
            }
            ans.push_back(mxi);
        }
        return ans;
    }
};

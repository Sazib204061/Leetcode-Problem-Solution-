class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<pair<int,int>>t;
        for(int i = 0; i<timePoints.size(); i++)
        {
            int x = ((timePoints[i][0]-'0')*10)+(timePoints[i][1]-'0');
            int y = ((timePoints[i][3]-'0')*10)+(timePoints[i][4]-'0');
            t.push_back({x,y});
        }
        sort(t.begin(), t.end());
        int ans = 100000000;

        t.push_back({t[0].first+23, t[0].second+60});

        for(int i = 0; i<t.size()-1; i++)
        {
            if(t[i]==t[i+1])
            {
                return 0;
            }
            else
            {
                //cout<<t[i+1].first<<" "<<t[i+1].second<<endl;
                int x = (t[i+1].first-t[i].first)*60+(t[i+1].second-t[i].second);
                ans = min(ans, x);
            }
        }
        return ans;
    }
};

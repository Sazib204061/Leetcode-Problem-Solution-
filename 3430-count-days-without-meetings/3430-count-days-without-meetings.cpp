class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int end = 0, ans = 0;
        for(int i = 0; i<meetings.size(); i++)
        {
            int st = meetings[i][0];
            int ed = meetings[i][1];
            if(st>end)
            {
                ans+=(st-end-1);
            }
            end = max(end, ed);
        }
        ans+=(days-end);  //edge case
        return ans;
    }
};
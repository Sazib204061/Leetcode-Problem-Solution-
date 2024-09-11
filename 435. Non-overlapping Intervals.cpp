
class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        int prev = 0, cnt = 1;
        for(int i = 1; i<n; i++)
        {
            if(intervals[i][0]>=intervals[prev][1])   //কত গুলো নন ওভারল্যপিং পসিবল তা কাউন্ট করি
            {
                cnt++;
                prev = i;
            }
        }
        return n-cnt;
    }
    
};

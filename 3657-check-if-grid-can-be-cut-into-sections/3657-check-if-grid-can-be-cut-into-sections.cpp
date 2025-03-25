class Solution {
public:
    bool isTowCutPossible(vector<pair<int,int>>intervals)
    {
        int numberOfCuts = 0, lastEnd = 0, NumberOfRectangleUsed = 0;
        for(auto it : intervals)
        {
            if(it.first>=lastEnd)
            {
                if(NumberOfRectangleUsed>0 && NumberOfRectangleUsed<intervals.size())
                {
                    numberOfCuts++;
                }
            }
            NumberOfRectangleUsed++;
            lastEnd = max(lastEnd, it.second);
        }
        if(numberOfCuts>=2)return true;
        return false;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>>X, Y;
        for(int i = 0; i<rectangles.size(); i++)
        {
            X.push_back({rectangles[i][0], rectangles[i][2]});
            Y.push_back({rectangles[i][1], rectangles[i][3]});
        }

        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());

        return (isTowCutPossible(X) | isTowCutPossible(Y));
    }
};
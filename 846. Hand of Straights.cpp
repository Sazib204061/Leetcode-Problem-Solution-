class Solution {
public:
    bool check(vector<int>& hand, int groupSize, int i)
    {
        int req = hand[i]+1, n = hand.size(), cnt = 1;
        if(cnt==groupSize)return true;
        i++;
        while(i<n)
        {
            if(hand[i]==req)
            {
                cnt++;
                hand[i] = -1;
                req++;
                if(cnt==groupSize)
                {
                    return true;
                }
            }
            i++;
        }
        return false;

    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0)return false;
        sort(hand.begin(), hand.end());

        for(int i = 0; i<n; i++)
        {
            if(hand[i]>=0 && !check(hand, groupSize, i))return false;

        }

        return true;

    }
};

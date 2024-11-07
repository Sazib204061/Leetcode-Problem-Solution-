class Solution {
public:
    int largestCombination(vector<int>& candidates) {

        vector<int>bit(32,0);
        for(int i = 0; i<candidates.size(); i++)
        {
            int n = candidates[i], bt = 0;
            while(n>0)
            {
                if((n&1))
                {
                    bit[bt]++;
                    
                }
                n = n>>1;
                bt++;
            }
        }
        int mx = 0;
        for(int i = 0; i<32; i++)
        {
            //cout<<bit[i]<<" "<<endl;
            mx = max(mx, bit[i]);
        }
        return mx;
    }
};

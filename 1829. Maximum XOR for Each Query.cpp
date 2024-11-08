class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int>ar, ans;
        int n = (1 << maximumBit)-1, val = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            val = val ^ nums[i];
            ar.push_back(val);
        }
        for(int i = ar.size()-1; i>=0; i--)
        {
            ans.push_back(n^ar[i]);
        }
        return ans;
    }
};

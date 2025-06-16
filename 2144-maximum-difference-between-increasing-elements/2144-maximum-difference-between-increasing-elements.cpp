class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[n-1], ans = -1;
        for(int i = n-2; i>=0; i--)
        {
            if(nums[i]<mx)
            {
                ans = max(ans, mx-nums[i]);
            }
            else
            {
                mx = nums[i];
            }
        }
        return ans;
    }
};
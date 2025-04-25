class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, preSum = 0;
        unordered_map<int,int>cnt;
        cnt[0] = 1;
        for(int i = 0; i<n; i++)
        {
            if(nums[i]&1)preSum++;
            if(preSum>=k)
            {
                int need = preSum-k;
                ans+=cnt[need];
            }
            cnt[preSum]++;
        }
        return ans;
    }
};
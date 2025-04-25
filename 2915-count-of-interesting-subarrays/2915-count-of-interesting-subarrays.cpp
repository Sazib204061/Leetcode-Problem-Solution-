class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        unordered_map<int,int>cnt;
        long long ans = 0;
        int prefix = 0;
        cnt[0] = 1;
        for(int i = 0; i<n; i++)
        {
            if(nums[i]%modulo==k)
            {
                prefix++;
            }
            ans += cnt[(prefix-k+modulo)%modulo];

            cnt[prefix%modulo]++;
        }
        return ans;
    }
};
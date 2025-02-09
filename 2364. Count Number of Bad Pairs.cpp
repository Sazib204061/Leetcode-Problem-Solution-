class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        unordered_map<long long,long long>mp;
        for(int i = 0; i<n; i++)
        {
            mp[nums[i]-i]++;
        }

        long long ans = (n*(n-1))/2;

        for(auto it : mp)
        {
            long long x = it.second;
            ans-=(x*(x-1))/2;
        }

        return ans;
    }
};

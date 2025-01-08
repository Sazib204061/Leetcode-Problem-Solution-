class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long sum = 0, ans = -1, n = nums.size(), ind_cnt = 0;
        for(int i = 0; i<n; i++)
        {
            if(ind_cnt>=2 && sum>nums[i])
            {
                ans = max(ans, sum+nums[i]);
            }
            sum+=nums[i];
            ind_cnt++;
        }

        return ans;
    }
};

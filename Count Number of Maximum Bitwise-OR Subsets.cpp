class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size(), mx_or = 0, ans = 0;
        for(int i = 0; i<n; i++)
        {
            mx_or = mx_or | nums[i];
        }

        for(int i = 0; i<(1<<n); i++)
        {
            int temp_or = 0;
            for(int j = 0; j<n; j++)
            {
                if(i& (1<<j))
                {
                    temp_or = temp_or | nums[j];
                }
            }
            if(temp_or==mx_or)ans++;
        }
        return ans;
    }
};



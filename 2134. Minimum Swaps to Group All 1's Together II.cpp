class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), one = 0, ans = INT_MAX;
        for(int i = 0; i<n; i++)
        {
            if(nums[i]==1)
            {
                one++;
            }
        }
        int zero = 0;
        for(int i = 0; i<one; i++)
        {
            if(nums[i]==0)
            {
                zero++;
            }
        }
        ans = min(ans, zero);
        int l = 0, r = one-1;
        while(l<n-1)
        {
            if(nums[l]==0)
            {
                zero--;
            }
            l++; r = (r+1)%n;

            if(nums[r]==0)
            {
                zero++;
            }
            //cout<<l<<" "<<r<<" "<<zero<<endl;
            ans = min(ans, zero);
        }
        return ans;
    }
};

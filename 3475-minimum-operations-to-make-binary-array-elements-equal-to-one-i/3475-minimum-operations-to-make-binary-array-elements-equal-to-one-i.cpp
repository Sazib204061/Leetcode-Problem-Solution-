class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 2, op = 0;
        for(l; r<n; )
        {
            if(nums[l]==0)
            {
                if(r-l!=2)
                {
                    return -1;
                }
                else
                {
                    nums[l] ^=1;
                    nums[l+1]^=1;
                    nums[r]^=1;
                    l++;
                    r++;
                    op++;
                }
            }
            else
            {
                r++;
                l++;
            }
        }
        if(r==n)r = n-1;
        if(nums[r]==0 || nums[r-1]==0 || nums[r-2]==0)return -1;
        return op;
    }
};
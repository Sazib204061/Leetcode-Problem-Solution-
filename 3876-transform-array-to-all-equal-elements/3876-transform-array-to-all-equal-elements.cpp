class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size(), K = k;
        bool ans = true;

        vector<int>nums1 = nums;

        for(int i = 0; i<n; i++)
        {
            if(nums[i]==-1)
            {
                if(i==n-1 || k<=0)
                {
                    ans = false;
                    break;
                }
                else
                {
                    nums[i]*=-1;
                    nums[i+1]*=-1;
                    k--;
                }
            }
        }

        if(ans) return ans;
        ans = true;
        k = K;
        for(int i = 0; i<n; i++)
        {
            if(nums1[i]==1)
            {
                if(i==n-1 || k<=0)
                {
                    ans = false;
                    break;
                }
                else
                {
                    nums1[i]*=-1;
                    nums1[i+1]*=-1;
                    k--;
                }
            }
        }
        


        
        return ans;
    }
};
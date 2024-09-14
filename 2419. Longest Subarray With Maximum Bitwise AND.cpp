class Solution {
public:
    int f(vector<int>&nums, int ind)
    {
        int n = nums.size(), i = ind, j = ind, a = nums[ind], b = nums[ind];
        while(i>=0)
        {
            a = a&nums[i];
            if(a<nums[ind])
            {
                i++;
                break;
            }
            else
            {
                if(i!=ind)
                    nums[i] = 0;
            }
            i--;
        }

        while(j<n)
        {
            b = b&nums[j];
            if(b<nums[ind])
            {
                j--;
                break;
            }
            else
            {
                if(j!=ind)
                    nums[j] = 0;
            }
            j++;
        }
        j = min(n-1, j);
        i = max(0, i);
        nums[ind] = 0;

        cout<<i<<" "<<j<<endl;

        return j-i+1;

    }
    int longestSubarray(vector<int>& nums) {
        int mx = 0, ans = 0, n = nums.size();
        for(int i = 0; i<n; i++)
        {
            mx = max(mx, nums[i]);
        }

        for(int i = 0; i<n; i++)
        {
            if(nums[i]==mx)
            {
                ans = max(ans, f(nums, i));
            }
        }

        return ans;


    }
};

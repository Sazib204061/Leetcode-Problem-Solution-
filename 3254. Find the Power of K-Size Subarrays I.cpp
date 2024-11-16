class Solution {
public:
    long long rang_series_sum(long long x, long long y)
    {
        return (y*(y+1)/2 - x*(x+1)/2 + x);
    }
    vector<int> resultsArray(vector<int>& nums, int k) {
        long long l = 0, r = k-1, sum = 0, n = nums.size();
        for(long long i = 0; i<k; i++)
        {
            sum+=nums[i];
        }
        vector<int>ans;
        long long first = nums[l], second = nums[r], rng_sum = rang_series_sum(first, second);

        if(sum==rng_sum)
        {
            ans.push_back(second);
        }
        else ans.push_back(-1);
        while(1)
        {
            sum-=nums[l];
            l++;
            if(l<n){
                first = nums[l];
            }
            else break;

            r++;
            if(r<n)
            {
                sum+=nums[r];
                second = nums[r];
                rng_sum = rang_series_sum(first, second);

                if(sum==rng_sum)
                {
                    ans.push_back(second);
                }
                else ans.push_back(-1);
            }
            else break;
        }

        return ans;

    }
};

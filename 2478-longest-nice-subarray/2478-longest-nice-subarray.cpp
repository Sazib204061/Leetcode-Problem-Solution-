class Solution {
public:

    
    bool is_addable(int n, int sum)  //check all pair AND is zero or not
    {
        return !(n&sum);
    }
    int add(int n, int sum)
    {
        return (n|sum);
    }
    int remove(int n, int sum)
    {
        return ((~n)&sum);
    }
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0;
        int n = nums.size(), sum = 0;
        for(int i = 0, j = 0; i<n && j<n; )
        {
            if(is_addable(nums[j], sum))
            {
                sum = add(nums[j], sum);
                j++;
                ans = max(ans, (j-i));
            }
            else
            {
                sum = remove(nums[i], sum);
                i++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int one = 0, zero = 0, zigzag = 1;
        for(int i = 0; i<n; i++)
        {
            nums[i]%=2;
            if(nums[i])one++;
            else zero++;
        }
        
        for(int i = 0; i<n-1; i++)
        {
            if(nums[i]!=nums[i+1])zigzag++;
        }
        return max(one, max(zero, zigzag));
    }
};
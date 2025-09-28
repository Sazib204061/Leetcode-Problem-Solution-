class Solution {
public:
    bool isValidTriangle(int a, int b, int c)
    {
        if(a+b>c && a+c>b && b+c>a)return true;
        return false;
    }
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i = 2; i<n; i++)
        {
            int a = nums[i-2];
            int b = nums[i-1];
            int c = nums[i];
            if(isValidTriangle(a, b, c))
            {
                return a+b+c;
            }
        }
        return 0;
    }
};
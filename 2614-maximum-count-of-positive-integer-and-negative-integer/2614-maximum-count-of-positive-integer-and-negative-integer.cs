public class Solution {
    public int MaximumCount(int[] nums) {
        int n = nums.Length, pos = 0, neg = 0;
        for(int i = 0; i<n; i++)
        {
            if(nums[i]<0)neg++;
            else if(nums[i]>0)pos++;
        }
        return Math.Max(neg, pos);
    }
}
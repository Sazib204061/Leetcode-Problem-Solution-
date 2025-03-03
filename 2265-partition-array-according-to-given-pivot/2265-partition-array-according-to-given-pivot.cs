public class Solution {
    public int[] PivotArray(int[] nums, int pivot) {
        int len = nums.Length;
        List<int> small = new List<int>(), large = new List<int>(), equal = new List<int>();
        for(int i = 0; i<len; i++)
        {
            if(nums[i]<pivot)
            {
                small.Add(nums[i]);
            }
            else if(nums[i]>pivot)
            {
                large.Add(nums[i]);
            }
            else
            {
                equal.Add(nums[i]);
            }
        }

        int ind_of_nums = 0;
        len = small.Count;
        for(int i = 0; i<small.Count; i++)
        {
            nums[ind_of_nums++] = small[i];
        }

        len = equal.Count;

        for(int i = 0; i<len; i++)
        {
            nums[ind_of_nums++] = equal[i];
        }

        len = large.Count;

        for(int i = 0; i<len; i++)
        {
            nums[ind_of_nums++] = large[i];
        }

        return nums;
    }
}
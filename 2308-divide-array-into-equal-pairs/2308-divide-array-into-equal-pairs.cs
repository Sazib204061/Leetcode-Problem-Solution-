public class Solution {
    public bool DivideArray(int[] nums) {
        int ArraySize = nums.Length;
        Dictionary<int,int>FrequencyCount = new Dictionary<int,int>();
        for(int i = 0; i<ArraySize; i++)
        {
            if(FrequencyCount.ContainsKey(nums[i]))
            {
                FrequencyCount[nums[i]]++;
            }
            else
            {
                FrequencyCount.Add(nums[i], 1);
            }
        }

        foreach(var i in FrequencyCount)
        {
            //Console.WriteLine(i.Key);
            if((i.Value) % 2!=0)return false;
        }


        return true;
    }
}
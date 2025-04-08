class Solution {
public:
    bool isDistinct(vector<int>&nums, int ind)
    {
        unordered_map<int,int>frequency;
        for(int i = ind; i<nums.size(); i++)
        {
            frequency[nums[i]]++;
            if(frequency[nums[i]]>1)
            {
                return false;
            }
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        int ind = 0, operation = 0, n = nums.size();
        while(1)
        {
            bool isDist = isDistinct(nums, ind);
            if(isDist==true)
            {
                return operation;
            }
            else
            {
                ind = min(ind+3, n);
            }
            operation++;
        }
        return 0;
    }
};
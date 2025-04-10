class Solution {
public:
    int NextZeroIndex(int currIndex, vector<int>&nums)
    {
        for(int i = currIndex+1; i<nums.size(); i++)
        {
            if(nums[i]==0)
            {
                return i;
            }
        }
        return -1;
    }
    int NextNonZeroIndex(int currIndex, vector<int>&nums)
    {
        for(int i = currIndex+1; i<nums.size(); i++)
        {
            if(nums[i]!=0)
            {
                return i;
            }
        }
        return -1;
    }
    void moveZeroes(vector<int>& nums) {
        int sizeOfArray = nums.size();
        int zeroIndex = -1, nonZeroIndex = -1;
        while(1)
        {
            zeroIndex = NextZeroIndex(zeroIndex, nums);
            if(zeroIndex==-1)break;
            nonZeroIndex = NextNonZeroIndex(zeroIndex, nums);
            if(nonZeroIndex==-1)break;
            
            swap(nums[zeroIndex], nums[nonZeroIndex]);
        }

    }
};
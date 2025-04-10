class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int arraySize = nums.size(), indexOfZero = 0, indexOfNonZero = 0;
        while(indexOfZero < arraySize)
        {
            if(nums[indexOfZero]==0)
            {
                while(indexOfNonZero < arraySize)
                {
                    if(nums[indexOfNonZero]!=0)
                    {
                        swap(nums[indexOfZero], nums[indexOfNonZero]);
                        break;
                    }
                    else
                    {
                        indexOfNonZero++;
                    }
                }
            }
            indexOfZero++;
            if(indexOfZero>indexOfNonZero)
            {
                indexOfNonZero = indexOfZero;
            }
        }
    }
};
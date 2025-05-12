class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>ans;
        int n = digits.size();
        unordered_map<int,int>check;
        for(int i = 0; i<n; i++)
        {
            if(digits[i]==0)continue;
            for(int j = 0; j<n; j++)
            {
                for(int k = 0; k<n; k++)
                {
                    if(i!=j && j!=k && i!=k)
                    {
                        if(digits[k]%2==0)
                        {
                            int number = (digits[i]*100)+(digits[j]*10)+digits[k];
                            if(!check[number]){
                                ans.push_back(number);
                            }
                            check[number]++;
                        }
                    }
                }
            }

        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
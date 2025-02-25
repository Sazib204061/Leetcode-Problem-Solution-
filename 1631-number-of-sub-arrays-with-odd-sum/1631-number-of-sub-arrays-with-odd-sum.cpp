class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int>pre_sum(n,0), previous_odd_pre_sum(n,0), previous_even_pre_sum(n,0);

        pre_sum[0] = arr[0];
        if(arr[0]&1)
        {
            previous_odd_pre_sum[0] = 1;
        }
        else
        {
            previous_even_pre_sum[0] = 1;
        }


        int ans = 0;
        if(arr[0]&1)ans++;

        for(int i = 1; i<n; i++)
        {
            pre_sum[i] = pre_sum[i-1]+arr[i];




            if(pre_sum[i]&1)
            {

                ans = (ans+previous_even_pre_sum[i-1]+1)%1000000007;


                previous_odd_pre_sum[i] = previous_odd_pre_sum[i-1]+1;
                previous_even_pre_sum[i] = previous_even_pre_sum[i-1];
            }
            else
            {

                ans = (ans+previous_odd_pre_sum[i-1])%1000000007;

                previous_odd_pre_sum[i] = previous_odd_pre_sum[i-1];
                previous_even_pre_sum[i] = previous_even_pre_sum[i-1]+1;
            }


        }
        return ans;

    }
};
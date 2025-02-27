class Solution {
public:
    unordered_map<int,int>mp;
    int lenLongestFibSubseq(vector<int>& arr) {
        mp.clear();
        int n = arr.size();
        for(int i = 0; i<n; i++)
        {
            mp[arr[i]] = i+1;
        }
        int ans = 0;
        for(int i = 0; i<n-2; i++)
        {
            int number_left = n-i;
            if(ans>number_left)break;
            int a = arr[i];
            for(int j = i+1; j<n-1; j++)
            {
                int number_left2 = n-j;
                int temp = 2;
                if(temp+number_left2<ans)break;
                a = arr[i];
                int b = arr[j];
                //temp++;
                int sum = a+b;
                if(sum>arr[n-1]) break;
                if(mp[sum]==0)
                {
                    continue;
                }
                
                temp++;
                //cout<<a<<" "<<b<<" "<<sum<<" "<<temp<<endl;
                int ind_sum = mp[sum]-1;
                while(ind_sum<n)
                {
                    a = b;
                    b = sum;
                    sum = a+b;
                    //cout<<a<<" "<<b<<" "<<sum<<endl;
                    if(mp[sum]==0)
                    {
                        break;
                    }
                    else
                    {
                        temp++;
                        ind_sum = mp[sum]-1;
                    }
                }
                ans = max(ans, temp);

            }
        }
        return ans;
    }
};
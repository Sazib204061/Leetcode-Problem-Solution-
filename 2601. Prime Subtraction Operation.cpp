#define lli long long int
const lli N = 10005;
#define lowb(a, x)  ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x)  ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
class Solution {
public:
    
    bitset<N+1>mark;
    vector<lli>primes;
    void sieve()
    {
        mark[2] = 0;
        primes.push_back(2);
        for(lli i = 4; i<=N; i+=2) mark[i] = 1;
        for(lli i = 3; i<=N; i+=2)
        {
            if(mark[i]==0)
            {
                for(lli j = i*i; j<=N; j+=i*2) mark[j] = 1;
                primes.push_back(i);
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        sieve();
        int n = nums.size();
        for(int i = n-2; i>=0; i--)
        {
            if(nums[i]>=nums[i+1])
            {
                int x = (nums[i]-(nums[i+1]-1));
                int ind = lowb(primes, x);
                if(primes[ind]<nums[i])
                {
                    nums[i] = nums[i]-primes[ind];
                }
                else return false;
            }
        }
        return true;
    }
};

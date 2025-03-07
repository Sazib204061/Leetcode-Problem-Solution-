public class Solution {
    public int N = 1000005;
    public bool [] mark = new bool[1000005];
    public List<int> primes = new List<int>();
    public void seive()
    {
        primes.Add(2);
        mark[2] = true;

        for(int i = 4; i<N; i+=2)
        {
            mark[i] = true;
        }
        for(int i = 3; i<N; i+=2)
        {
            if(!mark[i])
            {
                primes.Add(i);

                for(int j = i+i; j<N; j+=i)
                {
                    mark[j] = true;
                }

            }
        }

    }

    public Solution()
    {
        seive();
    }
    
    public int[] ClosestPrimes(int left, int right) {
        int Min_dif = 10000000;
        int n = primes.Count;
        int []ans = {-1,-1};
        for(int i = 0; i<n-1; i++)
        {
            if(primes[i]<left)continue;
            if(primes[i]>right || primes[i+1]>right)break;
            int dif = primes[i+1]-primes[i];
            if(dif<Min_dif)
            {
                ans[0] = primes[i];
                ans[1] = primes[i+1];
                Min_dif = dif;
            }
        }
        
        return ans;
    }
}
/*public class Solution {
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
}*/
//optimized (twin primes concept):
/*
A key mathematical observation under the given constraints (1 ≤ L,R ≤ 10^6) is that for any range [L, R] where R - L ≥ 1452, there is always at least one twin prime pair. This means that if the given range is wide enough (at least 1452 numbers long), we can be certain that a twin prime pair exists. Since no two prime numbers can be closer than a twin prime pair (which has a difference of exactly 2), we can immediately return this result without further searching.
*/
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int prevPrime = -1, closestA = -1, closestB = -1;
        int minDifference = 1e6;
        // Find all prime numbers in the given range
        for (int candidate = left; candidate <= right; candidate++) {
            if (isPrime(candidate)) {
                if (prevPrime != -1) {
                    int difference = candidate - prevPrime;
                    if (difference < minDifference) {
                        minDifference = difference;
                        closestA = prevPrime;
                        closestB = candidate;
                    }
                    // Twin prime optimization
                    if (difference == 2 or difference == 1)
                        return {prevPrime, candidate};
                }
                prevPrime = candidate;
            }
        }

        return (closestA == -1) ? vector<int>{-1, -1}
                                : vector<int>{closestA, closestB};
    }

private:
    bool isPrime(int number) {
        if (number < 2) return false;
        if (number == 2 || number == 3) return true;
        if (number % 2 == 0) return false;
        for (int divisor = 3; divisor * divisor <= number; divisor += 2) {
            if (number % divisor == 0) return false;
        }
        return true;
    }
};
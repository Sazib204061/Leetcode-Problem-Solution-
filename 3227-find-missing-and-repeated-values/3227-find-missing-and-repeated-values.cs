public class Solution {
    public int[] FindMissingAndRepeatedValues(int[][] grid) {
        Dictionary<int,int>frequency = new Dictionary<int,int>();
        int n = grid.Length, a = 0, b, sum = 0;
        int [] ans;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(!frequency.ContainsKey(grid[i][j]))
                {
                    sum+=grid[i][j];
                    frequency[grid[i][j]] = 1;
                }
                else
                {
                    a = grid[i][j];
                }
            }
        }
        n = n*n;
        int total_sum = ((n*(n+1))/2);
        b = total_sum-sum;

        ans = new int[] {a,b};


        return ans;

    }
}
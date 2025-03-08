public class Solution {
    public int MinimumRecolors(string blocks, int k) {
        int n = blocks.Length;
        int w = 0, l = 0, r = k-1;
        for(int i = 0; i<k; i++)
        {
            if(blocks[i]=='W')w++;
        }
        int ans = w;
        while((r+1)<n)
        {
            if(blocks[l]=='W')w--;
            if(blocks[r+1]=='W')w++;
            ans = Math.Min(ans, w);
            l++; r++;
        }

        return ans;
    }
}
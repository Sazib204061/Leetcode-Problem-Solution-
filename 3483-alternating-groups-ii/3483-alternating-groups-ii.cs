public class Solution {
    public int NumberOfAlternatingGroups(int[] colors, int k) {
        int answer = 0, problem = 0, n = colors.Length, L = 0, R = k-1;
        for(int i = 0; i<k-1; i++)
        {
            if(colors[i]==colors[i+1])
            {
                problem++;
            }
        }
        while(L<n-1)
        {
            //Console.WriteLine(L + " " + R);
            if(problem==0)answer++;
            int next_L = (L+1)%n;
            int next_R = (R+1)%n;

            if(colors[L]==colors[next_L])
            {
                problem--;
            }
            if(colors[R]==colors[next_R])
            {
                problem++;
            }
            L++;
            R = next_R;

        }

        if(problem==0)answer++;

        return answer;       

    }
}
class Solution {
public:
    int getStep(long long a, long long b, long long n)
    { //a থেকে b এর মধ্যে n এর ছোট বা সমান কত গুলো সংখ্যা আছে তা রির্টটান করবে।
        int gap = 0;
        while(a<=n)
        {
            gap+=min(n+1, b)-a;
            a*=10;
            b*=10;
        }
        return gap;
    }
    int findKthNumber(int n, int k) {
        long long curr = 1;
        k-=1;
        while(k>0)
        {
            int step = getStep(curr, curr+1, n); 
            if(step<=k)   //যত গুলো সংখ্যা পাইছি k তার থেকে বেশি।  তাই পরবর্ততী প্রিফিক্স দিয়ে খুজবো। এবং current prefix use করে যতগুলো সংখ্যা আছে k থেকে তা বাদ দিয়ে দিবো।
            {
                k-=step;
                curr+=1;
            }
            else
            {
                curr*=10;
                k-=1;
            }
        }
        return curr;
    }
};

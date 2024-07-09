class Solution {
public:

    double fcfs(vector<vector<int>>& customers)
    {
        int n = customers.size();
        double ct = customers[0][0]+customers[0][1];
        double wt = ct-customers[0][0];

        for(int i = 1; i<n; i++)
        {
            if(customers[i][0]>=ct)ct = customers[i][0];
            ct+=customers[i][1];
            //cout<<i<<" "<<ct<<endl;
            wt+=(ct-customers[i][0]);
        }
        return wt/(double)n;
    }
    double averageWaitingTime(vector<vector<int>>& customers) {
        return fcfs(customers);
    }
};

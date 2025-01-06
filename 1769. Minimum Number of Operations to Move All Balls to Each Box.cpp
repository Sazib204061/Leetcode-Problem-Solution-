class Solution {
public:

//O(n^2)
/*
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int>ans;
        for(int i = 0; i<n; i++)
        {
            int op = 0;
            for(int l = i-1; l>=0; l--)
            {
                if(boxes[l]=='1')
                {
                    op+=(i-l);
                }
            }

            for(int r = i+1; r<n; r++)
            {
                if(boxes[r]=='1')
                {
                    op+=(r-i);
                }
            }

            ans.push_back(op);
            
        }

        return ans;
    }

    */
    //O(n)
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int>distances(n,0), prefix(n,0), suffix(n,0);

        //calculate prefix array

        int pre_one_cnt = 0;
        int pre_one_ind_sum = 0;

        for(int i = 0; i<n; i++)
        {
            //calculate all distance form 0th index to ith index then minus double calculated distance
            prefix[i] = (pre_one_cnt*i)-pre_one_ind_sum; 

            if(boxes[i]=='1')
            {
                pre_one_cnt++;
                pre_one_ind_sum+=i;
            }
            
        }

        /*for(int i = 0; i<n; i++)
        {
            cout<<prefix[i]<<" ";
        }
        cout<<endl;*/


        //calculate suffix array

        int suf_one_cnt = 0;
        int suf_one_ind_sum = 0;
        int ind = 0;
        for(int i = n-1; i>=0; i--)
        {
            //calculate all distance form 0th index to ith index then minus double calculated distance
            suffix[i] = (suf_one_cnt*ind)-suf_one_ind_sum; 

            if(boxes[i]=='1')
            {
                suf_one_cnt++;
                suf_one_ind_sum+=ind;
            }
            ind++;
            
        }

        /*for(int i = 0; i<n; i++)
        {
            cout<<suffix[i]<<" ";
        }
        cout<<endl;*/


        for(int i = 0; i<n; i++)
        {
            distances[i] = prefix[i]+suffix[i];
        }

        return distances;



    }




};

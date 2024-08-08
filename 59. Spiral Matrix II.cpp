class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};  //r->d->l->t
        vector<vector<int>>ans(n, vector<int>(n, 0));
        int r = 0, c = 0, d = 0;   //d = 0->right, d = 1->down, d = 2->left, d = 3->top
    
        ans[0][0] = 1;
        int next_element = 2;

        while(next_element<=n*n)
        {
            
            while(1)
            {
                //cout<<r<<" "<<c<<endl;
                r+=dir[d][0];
                c+=dir[d][1];
                if(r>=0 && r<n && c>=0 && c<n && ans[r][c]==0)
                {
                    ans[r][c] = next_element;
                    next_element++;
                }
                else
                {
                    r-=dir[d][0];
                    c-=dir[d][1];
                    break;
                }
            }
            d = (d+1)%4;
        }
        return ans;
    }
};

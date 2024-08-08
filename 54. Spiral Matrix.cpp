class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};  //r->d->l->t
        vector<int>ans;
        int r = 0, c = 0, d = 0;   //d = 0->right, d = 1->down, d = 2->left, d = 3->top
        int n = matrix.size(), m = matrix[0].size();
        ans.push_back(matrix[0][0]);
        matrix[0][0] = -200;
        while(ans.size()<n*m)
        {
            
            while(1)
            {
                //cout<<r<<" "<<c<<endl;
                r+=dir[d][0];
                c+=dir[d][1];
                if(r>=0 && r<n && c>=0 && c<m && matrix[r][c]!=-200)
                {
                    ans.push_back(matrix[r][c]);
                    matrix[r][c] = -200;
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

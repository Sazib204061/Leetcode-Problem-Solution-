/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};  //r->d->l->t
        vector<vector<int>>ans(m, vector<int>(n, -2));
        int r = 0, c = 0, d = 0;   //d = 0->right, d = 1->down, d = 2->left, d = 3->top

        ans[0][0] = head->val;
        head = head->next;

        int total_element = 1;
        while(total_element<=m*n)
        {
            while(total_element<=m*n)
            {
                //cout<<r<<" "<<c<<" "<<total_element<<endl;
                r+=dir[d][0];
                c+=dir[d][1];
                if(r>=0 && r<m && c>=0 && c<n && ans[r][c]==-2)
                {
                    
                    if(head==NULL)
                    {
                        ans[r][c] = -1;
                    }
                    else{
                        ans[r][c] = head->val;
                        head = head->next;
                    }
                    total_element++;
                }
                else
                {

                    r-=dir[d][0];
                    c-=dir[d][1];
                    //cout<<r<<" "<<c<<" "<<ans[r][c]<<endl;
                    break;
                }
                if(total_element==m*n)break;
            }
            if(total_element==m*n)break;
            d = (d+1)%4;
        }
        return ans;
    }
};

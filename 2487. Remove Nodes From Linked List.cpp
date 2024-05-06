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
    ListNode* removeNodes(ListNode* head) {
        vector<int>ar;
        
        while(head!=NULL)
        {
            ar.push_back(head->val);
            head = head->next;
        }

        ListNode* ans = new ListNode();
        int i = ar.size()-1, prev;
        ans->val = ar[i];
        prev = ar[i];
        while(1)
        {
            i--;
            if(i<0)break;
            if(ar[i]>=prev)
            {
                ListNode* temp = new ListNode();
                temp->val = ar[i];
                temp->next = ans;
                ans = temp;
                prev = ar[i];
            }
        }
        return ans;
    }
};

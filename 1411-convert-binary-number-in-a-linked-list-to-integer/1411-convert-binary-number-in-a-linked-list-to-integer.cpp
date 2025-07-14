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
    
    int getDecimalValue(ListNode* head) {
        string s = "";
        while(head!=NULL)
        {
            s+=to_string(head->val);
            head = head->next;
        }
        //cout<<s<<endl;
        int pos = 0, ans = 0;
        for(int i = s.size()-1; i>=0; i--)
        {
            if(s[i]=='1')
            {
                ans+=(1<<pos);
            }
            pos++;
        }
        return ans;
    }
};
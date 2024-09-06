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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int,int>mp;
        for(int i = 0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        ListNode* ans = new ListNode();
        ListNode* x = ans;
        ListNode* temp = head;

        int cnt = 0;
        while(temp!=NULL)
        {
            int n = temp->val;
            if(mp[n]==0)
            {
                if(cnt==0)
                {
                    x->val = n;
                    cnt++;
                }
                else
                {
                    ListNode* y = new ListNode();
                    y->val = n;
                    x->next = y;
                    x = y;
                }
            }
            temp = temp->next;
        }
        return ans;
    }
};

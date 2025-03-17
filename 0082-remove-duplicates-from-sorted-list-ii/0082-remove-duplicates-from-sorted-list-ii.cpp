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
    ListNode* deleteDuplicates(ListNode* head) {
        //if(head==NULL)return head;
        vector<int>numbers;
        map<int,int>frequency;
        while(head!=NULL)
        {
            frequency[head->val]++;
            numbers.push_back(head->val);
            head = head->next;
        }
        ListNode*ans = new ListNode();
        ListNode*currNode = ans;
        int isItFirstNode = 0;
        for(int i = 0; i<numbers.size(); i++)
        {
            if(frequency[numbers[i]]>1)
            {
                continue;
            }
            else
            {

                isItFirstNode++;
                if(isItFirstNode==1)
                {
                    currNode->val = numbers[i];
                }
                else
                {
                    ListNode*newNode = new ListNode(numbers[i]);
                    currNode->next = newNode;
                    currNode = newNode;
                }
            }
        }

        if(isItFirstNode==0)return NULL;

        return ans;
    }
};
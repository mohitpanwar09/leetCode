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
    #define bb "\n"
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        
        ListNode *leftE=NULL;
        ListNode *s=head,*e=NULL;
        for(int i=1;i<l;i++)
        {
            leftE=s;
            s=s->next;
        }
        // cout<<leftE->val<<bb;
        e=s;
        for(int i=0;i<r-l;i++)
        {
            e=e->next;
        }
        
        ListNode *pre=NULL,*mid=s,*nextE;
        
        if(s!=NULL && e!=NULL)
        {
            while(mid!=e)
            {
                nextE=mid->next;
                mid->next=pre;
                pre=mid;
                mid=nextE;
            }
            nextE=mid->next;
            mid->next=pre;

            s->next=nextE;
            if(leftE!=NULL)
            leftE->next=mid;
            else
                head=mid;
            }
        
        return head;
    }
};
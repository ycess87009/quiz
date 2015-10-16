/* FIXME: Implement! */
#include<stdio.h>

typedef struct ListNode {
    struct ListNode *pNext;
} ListNode;

int main()
{
    return 0;
}
/*
 *  find the node which is the cycle begins
 *  parameters   :  head of linked list
 *  return value :  the node which is the cycle begins
 *                  if there is no cycle,return NULL
 */

ListNode *detectCycle(ListNode *head)
{
    if(head == NULL || head->pNext == NULL) {
        return NULL;
    }
    ListNode *slow=head;
    ListNode *fast=head;
    /*
     * Two traversals with different speed will meet at the same node if there is a cycle.
     * We can find the node which is the cycle begins.
     */
    while(fast->pNext!=NULL && fast->pNext->pNext!=NULL) {
        fast=fast->pNext->pNext;
        slow=slow->pNext;
        if(fast == slow) {
            slow = head;
            while(slow != fast) {
                fast = fast->pNext;
                slow = slow->pNext;
            }
            return slow;
        }
    }
    return NULL;
}


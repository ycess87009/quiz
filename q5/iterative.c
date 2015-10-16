/* FIXME: Implement! */
#define NULL 0

typedef struct ListNode
{
    struct ListNode *pNext;
}ListNode;

int main()
{
    return 0;
}

ListNode *detectCycle(ListNode *head)
{
    if(head == NULL || head->pNext == NULL)
    {
        return NULL;
    }
    ListNode *slow=head;
    ListNode *fast=head;
    unsigned int count=0;
    while(fast->pNext!=NULL && fast->pNext->pNext!=NULL)
    {
        fast=fast->pNext->pNext;
        slow=slow->pNext;
        if(fast == slow)
        {
            slow = head;
            while(slow != fast)
            {
                fast = fast->pNext;
                slow = slow->pNext;
            }
            return slow;
        }
    }
    return NULL;
}


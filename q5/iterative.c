/* FIXME: Implement! */
#include<stdio.h>
#include<stdlib.h>
#include"time_routine.h"

typedef struct ListNode {
    struct ListNode *pNext;
} ListNode;

ListNode *detectCycle(ListNode *head);

int main()
{

    //setup Random number seed
    srand((unsigned)time(NULL));
    unsigned int nodes=1+rand()%200;
    int loop=rand()%2;//determine if there is a cycle in list.
    struct timespec start, end;
    double cpu_time;
    //generate linked list
    int count=1,cycle_begin=-1;
    if(loop)
        cycle_begin=rand()%(nodes);
    ListNode *head=malloc(sizeof(ListNode));
    ListNode *e=head;
    ListNode *record;
    for(; count<nodes; count++) {
        e->pNext=malloc(sizeof(ListNode));
        if(count==cycle_begin) {
            record=e;
        }
        e=e->pNext;
    }
    if(loop)
        e->pNext=record;
    else
        e->pNext=NULL;

    clock_gettime(CLOCK_REALTIME, &start);
    ListNode *result=detectCycle(head);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_second(start, end);
    //Cycle exist->check result==record ,no Cycle->result should be NULL.
    if((loop==1 && (result==record))|| (loop==0 && result==NULL))
        printf("Correct! Time: %lf sec.\n",cpu_time);
    else
        printf("Wrong\n");

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


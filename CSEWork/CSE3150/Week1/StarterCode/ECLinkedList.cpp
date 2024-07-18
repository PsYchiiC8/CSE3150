#include "ECLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/* get the length of the linked list: how many nodes in the linked list */
/* pHead: head node pointer to the linked list */
/* return the number of nodes of the linked list pointed by pHead */
int ECGetLinkedListLength(struct ECLinkedListNode *pHead )
{
    /* your code here */
    int res = 0;
    struct ECLinkedListNode *pCurr = pHead;

    while(pCurr != NULL){
        pCurr = pCurr->pNext;
        res++;
    }

    return res;

}

/* delete all nodes with a specific value from the linked list */
/* input: pHead: head node pointer to the linked list which to be processed */
/* input: val: all nodes with value equal to val should be deleted */
/* output: the pointer to the head node of the linked list after the delete operation */
struct ECLinkedListNode *ECLinkedListDeleteVal(struct ECLinkedListNode *pHead, int val){
    /* your code here */

    struct ECLinkedListNode *pCurr = pHead;
    struct ECLinkedListNode *pPre = NULL;
    struct ECLinkedListNode *pHeadNew = NULL;
    struct ECLinkedListNode *pDel = NULL;
    while(pCurr != NULL)
    {
        pDel = NULL;
        if(pCurr->value == val){
            if(pPre != NULL){
                pPre->pNext = pCurr->pNext;
            }
            pDel = pCurr;
        }
        else if(pHeadNew == NULL){
            pHeadNew = pCurr;
            pPre = pCurr;
        }
        pCurr = pCurr->pNext;
        if(pDel != NULL){
            free(pDel);
        }
    }
    return pHeadNew;
}

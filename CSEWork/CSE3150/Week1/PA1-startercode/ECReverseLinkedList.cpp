#include "ECReverseLinkedList.h"
#include <stdio.h>
//#include <stdlib.h>

/* Reverse the given linked list */
/* pHead: head node pointer to the linked list */
/* return the head of the reversed linked list */
/* note: don't allocate any new space using malloc; you should be able to reverse the linked list by just changing the pointers */
struct ECLinkedListNode* ECReverseLinkedList( struct ECLinkedListNode *pHead )
{
  /* Your code goes here */

  if(pHead == NULL || pHead->pNext == NULL){
      return pHead;
  }

  struct ECLinkedListNode* pPrev = NULL;
  struct ECLinkedListNode* pCurr = pHead;
  struct ECLinkedListNode* pNext = NULL;

  while (pCurr != NULL){
    pNext = pCurr->pNext;
    pCurr->pNext = pPrev;
    pPrev = pCurr;
    pCurr = pNext;
  }

  return pPrev;
}


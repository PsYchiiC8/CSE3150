#include "ECListNode.h"
#include "ECList.h"

// Linked list 
ECList::ECList() {
    numNodes = 0;
    pHead = nullptr;
}

// insert node with value val after a node
// if node is NULL, insert to the front
void ECList::Insert(int val, ECListNode *pPre) {
    ECListNode* newNode = new ECListNode(val);

    if (pPre == nullptr) {
        newNode->SetNext(pHead);
        pHead = newNode;
        ++numNodes;
        return;
    } else {
        ECListNode* pTemp = pHead;

        while (pTemp != nullptr && pTemp != pPre){
            pTemp = pTemp->GetNext();
        }

        if (pTemp == nullptr) {
            // pPre not found in the list
            delete newNode; // Avoid memory leak
            return;
        }

        newNode->SetNext(pTemp->GetNext());
        pTemp->SetNext(newNode);
        ++numNodes;
    }
}

// delete a node
void ECList::Delete(ECListNode *pNode) {
    if(pHead == nullptr){
        return;
    }

    ECListNode* pCur = pHead;

    while (pCur != nullptr && pCur->GetNext() != pNode){
        pCur = pCur->GetNext();
    }

    if (pCur == nullptr){
        return;
    }
    pCur->SetNext(pNode->GetNext());
    --numNodes;

    // deleting
//    delete pNode;
}

// get a node with value; if multiple nodes with the same value, return the first from head
ECListNode *ECList::GetNode(int val) {
    if (pHead == nullptr){
        return nullptr;
    }

    ECListNode* pCur = pHead;

    while (pCur != nullptr && pCur->GetValue() != val){
        pCur = pCur->GetNext();
    }

    if (pCur == nullptr){
        return nullptr;
    }

    return pCur;
}

// get the number of nodes in the list
int ECList::GetSize() const {
    return numNodes;
}


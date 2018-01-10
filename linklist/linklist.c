#include "linklist.h"

/******************************************************************************
* Name       : T_NODE *CreateList(void)
* Function   : Create a List
* Input      : None
* Output:    : None
* Return     : NULL :Create list failed
*              pHead:The address of the create list
* Description: None
* Version    : V1.00
* Author     : XZP
* Date       : 9th Jan 2018
******************************************************************************/
T_NODE *CreateList(void)
{
    T_NODE *pHead;
    
    pHead = (T_NODE *)malloc(sizeof(T_NODE));
    if (NULL == pHead)
    {
        printf("Create List Failed!");
        return NULL;
    }
    pHead->pNext = NULL;
    return pHead;
}

/******************************************************************************
* Name       : unsigned char InsertList(T_NODE **pHead,unsigned int wData,unsigned char ucAddPlace)
* Function   : Insert a node into list
* Input      : T_NODE **pHead          :The head of list
*              unsigned int wData      :The data to be inserted
*              unsigned char ucAddPlace:The place of the node to inserted
* Output:    : None
* Return     : FAULT:Insert list failed
*              TRUE: Insert list success
* Description: The place of the data to inserted is behind ucAddPlace.For example:if ucAddPlace is 1,
*              The place of the data to inserted is behind place 1,so insert place is 2.
* Version    : V1.00
* Author     : XZP
* Date       : 9th Jan 2018
******************************************************************************/
unsigned char InsertList(T_NODE **pHead,unsigned int wData,unsigned char ucInsertPlace)
{
    T_NODE *pTail,*pAdd;
	unsigned char ucCount = 0;

    pTail = (*pHead);
    if (0 == ucInsertPlace)  /* Insert data to head */
    {
        pAdd = (T_NODE *)malloc(sizeof(T_NODE));
        if (NULL == pAdd)
        {
            printf("Add List Failed!");
            return FAULT;
        }
        pAdd->wData = wData;
        pAdd->pNext = pHead;
        (*pHead) = pAdd;
        return TRUE;
    }
    
    while (NULL != pTail)
    {
		ucCount++;
        if (ucCount == ucInsertPlace)
        {
            break;
        }
        pTail = pTail->pNext;
    }
    if (NULL == pTail)
    {
        return FAULT;
    }
    pAdd = (T_NODE *)malloc(sizeof(T_NODE));
    if (NULL == pAdd)
    {
        printf("Add List Failed!");
        return FAULT;
    }
    pAdd->wData  = wData;
    pAdd->pNext  = pTail->pNext;
    pTail->pNext = pAdd;

    return TRUE;
}

/******************************************************************************
* Name       : unsigned char DeleteList(T_NODE **pHead,unsigned char ucDelPlace)
* Function   : Delete a node from list
* Input      : T_NODE **pHead          :The head of list
*              unsigned char ucDelPlace:The place of the node to delete
* Output:    : None
* Return     : FAULT:Delete list failed
*              TRUE: Delete list success
* Description: The place of the data to delete is behind ucDelPlace.For example:if ucDelPlace is 1,
*              The place of the data to delete is behind place 1,so delete place is 2.
* Version    : V1.00
* Author     : XZP
* Date       : 9th Jan 2018
******************************************************************************/
unsigned char DeleteList(T_NODE **pHead,unsigned char ucDelPlace)
{
    T_NODE *pTail,*pDelete;
    unsigned char ucCount = 0;

    pTail = (*pHead);
    if (0 == ucDelPlace)  /* Delete the head data */
    {
        (*pHead) = pTail->pNext;
        free(pTail);
        return TRUE;
    }
    
    while (NULL != pTail)
    {
        ucCount++;
        if (ucCount == ucDelPlace)
        {
            break;
        }
        pTail = pTail->pNext;
    }
    if ((NULL == pTail->pNext) || (NULL == pTail))
    {
        return FAULT;
    }
    pDelete = pTail->pNext;
    pTail->pNext = pDelete->pNext;
    free(pDelete);

    return TRUE;
}

/******************************************************************************
* Name       : void DeleteAllList(T_NODE *pHead)
* Function   : Delete all node from list
* Input      : T_NODE *pHead :The head of list
* Output:    : None
* Return     : None
* Description: None
* Version    : V1.00
* Author     : XZP
* Date       : 9th Jan 2018
******************************************************************************/
void DeleteAllList(T_NODE *pHead)
{
    T_NODE *pDelete;

    while (NULL != pHead)
    {
        pDelete = pHead->pNext;
        free(pHead);
        pHead = pDelete;
    }
    
    return;
}

/******************************************************************************
* Name       : T_NODE *LocateList(T_NODE *pHead,unsigned char ucLocatePlace)
* Function   : Locate a node from list
* Input      : T_NODE *pHead              :The head of list
*              unsigned char ucLocatePlace:The locate place of the node
* Output:    : None
* Return     : NULL   :Locate node failed
*              pLocate:The address of the node
* Description: The place of the data to locate is behind ucLocatePlace.For example:if ucLocatePlace is 1,
*              The place of the data to locate is behind place 1,so locate place is 2.
* Version    : V1.00
* Author     : XZP
* Date       : 9th Jan 2018
******************************************************************************/
T_NODE *LocateList(T_NODE *pHead,unsigned char ucLocatePlace)
{
    T_NODE *pLocate;
    unsigned char ucCount = 0; 
        
    pLocate = pHead;
    while (NULL != pLocate)
    {
        if (ucLocatePlace == ucCount)
        {
            break;
        }
        ucCount++;
        pLocate = pLocate->pNext;
    }
    if (NULL == pLocate)
    {
        return NULL;
    }
    return pLocate;
}


/******************************************************************************
* Name       : void TraversalAllList(T_NODE *pHead)
* Function   : Traversal all node from list
* Input      : T_NODE *pHead :The head of list
* Output:    : None
* Return     : None
* Description: None
* Version    : V1.00
* Author     : XZP
* Date       : 9th Jan 2018
******************************************************************************/

void TraversalAllList(T_NODE *pHead)
{
    unsigned char ucCount = 0;

    while (NULL != pHead)
    {
        ucCount++;
        printf("No.%d:%d\r\n",ucCount,pHead->wData);
        pHead = pHead->pNext;
    }
    
    return;
}



#include "Linklist.h"

static T_NODE *gs_pHead = NULL;  /* The head of the linklist */

/******************************************************************************
* Name       : unsigned char CreateLinklist(void)
* Function   : Create a Linklist
* Input      : None
* Output:    : None
* Return     : FAULT:Create list failed
*              TRUE: Create list success
* Description: None
* Version    : V1.00
* Author     : XZP
* Date       : 11th Jan 2018
******************************************************************************/
unsigned char CreateLinklist(void)
{
    gs_pHead = (T_NODE *)malloc(sizeof(T_NODE));
    if (NULL == gs_pHead)
    {
        printf("Create Linklist Failed!");
        return FAULT;
    }
    gs_pHead->pNext = NULL;
    
    return TRUE;
}

/******************************************************************************
* Name       : T_NODE *InsertLinklist(unsigned int wData,unsigned char ucInsertPlace)
* Function   : Insert a node into linklist
* Input      : unsigned int wData      :The data to be inserted
*              unsigned char ucAddPlace:  
*                          LINKLIST_INSERT_HEAD:Inserted the node into head
*                          LINKLIST_INSERT_TAIL:Inserted the node into tail
* Output:    : None
* Return     : NULL:Insert list failed
*              pAdd:The address of insert node
* Description: None
* Version    : V1.00
* Author     : XZP
* Date       : 11th Jan 2018
******************************************************************************/
T_NODE *InsertLinklist(unsigned int wData,unsigned char ucInsertPlace)
{
    T_NODE *pTail,*pAdd;
    
    pTail = gs_pHead;
    if ((LINKLIST_INSERT_HEAD != ucInsertPlace) && (LINKLIST_INSERT_TAIL != ucInsertPlace))
    {
        printf("Insert linklist Place error!");
        return NULL;
    }
    
    pAdd = (T_NODE *)malloc(sizeof(T_NODE));
    if (NULL == pAdd)
    {
        printf("Insert linklist Failed!");
        return NULL;
    }
    
    if (LINKLIST_INSERT_HEAD == ucInsertPlace)  /* Insert data to head */
    {
        pAdd->wData = wData;
        pAdd->pNext = gs_pHead->pNext;
        gs_pHead->pNext = pAdd;
    }
    else    /* Insert data to tail */
    {
        while (NULL != pTail)
        {
            pTail = pTail->pNext;
        }
        pAdd->wData  = wData;
        pAdd->pNext  = NULL;
        pTail->pNext = pAdd;
    }
    
    return pAdd;
}

/******************************************************************************
* Name       : unsigned char DeleteLinklist(T_NODE *pDelAddr)
* Function   : Delete a node from list
* Input      : T_NODE *pDelAddr:The address of delete node
* Output:    : None
* Return     : FAULT:Delete list failed
*              TRUE: Delete list success
* Description: None
* Version    : V1.00
* Author     : XZP
* Date       : 11th Jan 2018
******************************************************************************/
unsigned char DeleteLinklist(T_NODE *pDelAddr)
{
    T_NODE *pTail,*pDelete;

    pTail = gs_pHead;
    if (gs_pHead == pDelAddr)  /* Delete the head data */
    {
        printf("Delete linklist Place error!");
        return FAULT;
    }
    
    while (NULL != pTail->pNext)
    {
        if (pTail->pNext == pDelAddr)
        {
            break;
        }
        pTail = pTail->pNext;        
    }
    if (NULL == pTail->pNext)
    {
        printf("Delete linklist Place error!");
        return FAULT;
    }
    pDelete = pTail->pNext;
    pTail->pNext = pDelete->pNext;
    free(pDelete);

    return TRUE;
}

/******************************************************************************
* Name       : void DeleteAllLinklist(void)
* Function   : Delete all node from list
* Input      : None
* Output:    : None
* Return     : None
* Description: None
* Version    : V1.00
* Author     : XZP
* Date       : 11th Jan 2018
******************************************************************************/
void DeleteAllLinklist(void)
{
    T_NODE *pDelete;
    
    while (NULL != gs_pHead->pNext)
    {
        pDelete = gs_pHead->pNext;
        gs_pHead->pNext = pDelete->pNext;
        free(pDelete);
    }
    
    return;
}

/******************************************************************************
* Name       : T_NODE *SeekLinklist(unsigned int wSeekData)
* Function   : Seek a node from list
* Input      : unsigned int wSeekData:The seek data
* Output:    : None
* Return     : NULL :seek node failed
*              pSeek:The address of seek node
* Description: None
* Version    : V1.00
* Author     : XZP
* Date       : 11th Jan 2018
******************************************************************************/
T_NODE *SeekLinklist(unsigned int wSeekData)
{
    T_NODE *pSeek;
    
    pSeek = gs_pHead->pNext; 
    while (NULL != pSeek)
    {
        if (pSeek->wData == wSeekData)
        {
            break;
        }
        pSeek = pSeek->pNext;        
    }
    if (NULL == pSeek)
    {
        printf("Seek linklist failed!");
        return NULL;
    }
    
    return pSeek;
}


/******************************************************************************
* Name       : void TraversalLinklist(void)
* Function   : Traversal all node from list
* Input      : None
* Output:    : None
* Return     : None
* Description: Printf all data
* Version    : V1.00
* Author     : XZP
* Date       : 11th Jan 2018
******************************************************************************/
void TraversalLinklist(void)
{
    T_NODE *pTail;
    unsigned char ucCount = 0;

    pTail = gs_pHead->pNext;
    while (NULL != pTail)
    {
        ucCount++;
        printf("No.%d:%d\r\n",ucCount,pTail->wData);
        pTail = pTail->pNext;
    }
    
    return;
}



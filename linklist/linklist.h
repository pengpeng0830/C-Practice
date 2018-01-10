#ifndef __LINKLIST_H_
#define __LINKLIST_H_

#ifdef __cplusplus
extern "C" {
#endif

#define FAULT   0
#define TRUE    1

typedef struct Node  
{  
    unsigned int wData;
    struct Node *pNext;
}T_NODE;

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
T_NODE *CreateList(void);

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
unsigned char InsertList(T_NODE **pHead,unsigned int wData,unsigned char ucInsertPlace);

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
unsigned char DeleteList(T_NODE **pHead,unsigned char ucDelPlace);

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
void DeleteAllList(T_NODE *pHead);

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
T_NODE *LocateList(T_NODE *pHead,unsigned char ucLocatePlace);

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
void TraversalAllList(T_NODE *pHead);

#ifdef __cplusplus
}
#endif

#endif /* __LINKLIST_H_ */


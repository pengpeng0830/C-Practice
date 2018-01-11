#ifndef __LINKLIST_H_
#define __LINKLIST_H_

#ifdef __cplusplus
extern "C" {
#endif

#define FAULT   (0)
#define TRUE    (1)

#define LINKLIST_INSERT_HEAD    (0)
#define LINKLIST_INSERT_TAIL    (1)

typedef struct Node  
{  
    unsigned int wData;
    struct Node *pNext;
}T_NODE;

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
unsigned char CreateLinklist(void);

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
T_NODE *InsertLinklist(unsigned int wData,unsigned char ucInsertPlace);

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
unsigned char DeleteLinklist(T_NODE *pDelAddr);

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
void DeleteAllLinklist(void);

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
T_NODE *SeekLinklist(unsigned int wSeekData);

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
void TraversalLinklist(void);

#ifdef __cplusplus
}
#endif

#endif /* __LINKLIST_H_ */


#ifndef __SOFTTIMER_H_
#define __SOFTTIMER_H_

#ifdef __cplusplus
extern "C" {
#endif

#define FAULT    (0)
#define TRUE     (1)

typedef uint32 (*PF_SOFTTIMER_CB)(void *pPara);

typedef struct _T_SOFTTIMER  
{  
    PF_SOFTTIMER_CB *pfSofttimerCB;   /* »Øµ÷º¯Êý */
    uint8  u8TaskID;                  /* ¶¨Ê±Æ÷ID */
    uint16 u16OldTime;                /* ³õÊ¼Ê±¼ä */
    uint16 u16Period;                 /* ¶¨Ê±Ê±¼ä */
    uint16 u16Count;                  /* Ö´ÐÐ´ÎÊý */
}T_SOFTTIMER;


typedef struct _T_SOFTTIMER_NODE
{  
    struct _T_SOFTTIMER_NODE *ptNext;
    T_SOFTTIMER tSofttimer;
}T_SOFTTIMER_NODE;


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
uint8 SofttimerInit(void);

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
uint16 CreateSofttimer(T_SOFTTIMER *ptSofttimer);

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
uint16 DeleteSofttimer(uint8 ucTaskID);

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
void DeleteAllSofttimer(void);

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
void ProcessSofttimer(uint16 uint16CurrentTime);



#ifdef __cplusplus
}
#endif

#endif /* __LINKLIST_H_ */


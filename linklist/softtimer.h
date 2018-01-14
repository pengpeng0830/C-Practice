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
    PF_SOFTTIMER_CB pfSofttimerCB;    /* »Øµ÷º¯Êý */
    uint8  u8TaskID;                  /* ¶¨Ê±Æ÷ID */
    uint16 u16OldTime;                /* »ù×¼Ê±¼ä */
    uint16 u16Period;                 /* ¶¨Ê±ÖÜÆÚ */
    uint16 u16Count;                  /* Ö´ÐÐ´ÎÊý */
}T_SOFTTIMER;


typedef struct _T_SOFTTIMER_NODE
{  
    struct _T_SOFTTIMER_NODE *ptNext;
    T_SOFTTIMER tSofttimer;
}T_SOFTTIMER_NODE;

extern PF_SOFTTIMER_CB g_aptSofttimerTimeout[E_SOFTTIMER_TASK_NUM];

/******************************************************************************
* Name       : uint8 SofttimerInit(void)
* Function   : Create a Linklist head
* Input      : None
* Output:    : None
* Return     : FAULT:Create linklist failed
*              TRUE: Create linklist success
* Description: None
* Version    : V1.00
* Author     : XZP
* Date       : 14th Jan 2018
******************************************************************************/
uint8 SofttimerInit(void);

/******************************************************************************
* Name       : uint16 CreateSofttimer(T_SOFTTIMER *ptSofttimer)
* Function   : Create a softtimer linklist to tail
* Input      : T_SOFTTIMER *ptSofttimer
* Output:    : None
* Return     : FAULT:Create new softtimer failed
*              TRUE: Create new softtimer success
* Description: None
* Version    : V1.00
* Author     : XZP
* Date       : 14th Jan 2018
******************************************************************************/
uint16 CreateSofttimer(T_SOFTTIMER *ptSofttimer);

/******************************************************************************
* Name       : uint16 DeleteSofttimer(uint8 u8TaskID)
* Function   : Delete a softtimer from list
* Input      : uint8 u8TaskID
* Output:    : None
* Return     : FAULT:Delete softtimer failed
*              TRUE: Delete softtimer success
* Description: None
* Version    : V1.00
* Author     : XZP
* Date       : 14th Jan 2018
******************************************************************************/
uint16 DeleteSofttimer(uint8 u8TaskID);

/******************************************************************************
* Name       : void DeleteAllSofttimer(void)
* Function   : Delete all softtimer from list
* Input      : None
* Output:    : None
* Return     : None
* Description: None
* Version    : V1.00
* Author     : XZP
* Date       : 14th Jan 2018
******************************************************************************/
void DeleteAllSofttimer(void);

/******************************************************************************
* Name       : void ProcessSofttimer(uint16 u16CurrentTime)
* Function   : Process softtimer
* Input      : uint16 u16CurrentTime
* Output:    : None
* Return     : None
* Description: None
* Version    : V1.00
* Author     : XZP
* Date       : 14th Jan 2018
******************************************************************************/
void ProcessSofttimer(uint16 u16CurrentTime);

#ifdef __cplusplus
}
#endif

#endif /* __LINKLIST_H_ */


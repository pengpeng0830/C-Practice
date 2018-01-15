#ifndef __SOFTTIMER_H_
#define __SOFTTIMER_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef uint32 (*PF_SOFTTIMER_CB)(void *pPara);

typedef struct _T_SOFTTIMER  
{  
    PF_SOFTTIMER_CB pfSofttimerCB;    /* 回调函数 */
    uint32 u32OldTime;                /* 基准时间 */
    uint32 u32Period;                 /* 定时周期 */
    uint16 u16Count;                  /* 执行次数 */
    uint8  u8TaskID;                  /* 定时器ID */
}T_SOFTTIMER;

typedef struct _T_SOFTTIMER_NODE
{  
    struct _T_SOFTTIMER_NODE *ptNext;
    T_SOFTTIMER tSofttimer;
}T_SOFTTIMER_NODE;

extern PF_SOFTTIMER_CB g_aptSofttimerTimeout[E_SOFTTIMER_TASK_NUM];

/******************************************************************************
* Name       : uint16 SofttimerInit(void)
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
uint16 SofttimerInit(void);

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
* Name       : void ProcessSofttimer(uint32 u32CurrentTime)
* Function   : Process softtimer
* Input      : uint32 u32CurrentTime
* Output:    : None
* Return     : None
* Description: None
* Version    : V1.00
* Author     : XZP
* Date       : 14th Jan 2018
******************************************************************************/
void ProcessSofttimer(uint32 u32CurrentTime);

#ifdef __cplusplus
}
#endif

#endif /* __LINKLIST_H_ */


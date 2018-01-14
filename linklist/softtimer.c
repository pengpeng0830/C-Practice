#include "Public.h"
#include "Softtimer.h"
#include "stdlib.h"

static T_SOFTTIMER_NODE *sg_ptSofttimerHead = NULL;  /* The head of the linklist */
PF_SOFTTIMER_CB g_aptSofttimerTimeout[E_SOFTTIMER_TASK_NUM] = {NULL};

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
uint8 SofttimerInit(void)
{
    uint8 u8TaskID;
    for (u8TaskID = 0; u8TaskID < E_SOFTTIMER_TASK_NUM; u8TaskID++)
    {
        g_aptSofttimerTimeout[u8TaskID] = NULL;
    }
    
    sg_ptSofttimerHead = (T_SOFTTIMER_NODE *)malloc(sizeof(T_SOFTTIMER_NODE));
    if (NULL == sg_ptSofttimerHead)
    {
        return FAULT;
    }
    sg_ptSofttimerHead->ptNext = NULL;
    
    return TRUE;
}

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
uint16 CreateSofttimer(T_SOFTTIMER *ptSofttimer)
{
    T_SOFTTIMER_NODE *ptTail,*ptAddSofttimer;
    if (NULL == sg_ptSofttimerHead)
    {
        return FAULT;
    }
    if ((NULL == ptSofttimer) || (0 == ptSofttimer->u16Count))
    {
        return FAULT;
    }
    ptTail = sg_ptSofttimerHead;
    ptAddSofttimer = (T_SOFTTIMER_NODE *)malloc(sizeof(T_SOFTTIMER_NODE));
    if (NULL == ptAddSofttimer)
    {
        return FAULT;
    }
    
    while (NULL != ptTail->ptNext)
    {
        ptTail = ptTail->ptNext;
    }
    ptAddSofttimer->tSofttimer.u16Count      = ptSofttimer->u16Count;
    ptAddSofttimer->tSofttimer.u16Period     = ptSofttimer->u16Period;
    ptAddSofttimer->tSofttimer.u16OldTime    = ptSofttimer->u16OldTime;
    ptAddSofttimer->tSofttimer.u8TaskID      = ptSofttimer->u8TaskID;
    ptAddSofttimer->tSofttimer.pfSofttimerCB = ptSofttimer->pfSofttimerCB;
    ptAddSofttimer->ptNext  = NULL;
    ptTail->ptNext = ptAddSofttimer;
    
    return TRUE;
}

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
uint16 DeleteSofttimer(uint8 u8TaskID)
{
    T_SOFTTIMER_NODE *ptTail,*ptDelete;

    ptTail = sg_ptSofttimerHead;
    
    while (NULL != ptTail->ptNext)
    {
        if (ptTail->ptNext->tSofttimer.u8TaskID == u8TaskID)
        {
            break;
        }
        ptTail = ptTail->ptNext;        
    }
    if (NULL == ptTail->ptNext)
    {
        return FAULT;
    }
    ptDelete = ptTail->ptNext;
    ptTail->ptNext = ptDelete->ptNext;
    free(ptDelete);

    return TRUE;
}

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
void DeleteAllSofttimer(void)
{
    T_SOFTTIMER_NODE *ptDelete;
    
    while (NULL != sg_ptSofttimerHead->ptNext)
    {
        ptDelete = sg_ptSofttimerHead->ptNext;
        sg_ptSofttimerHead->ptNext = ptDelete->ptNext;
        free(ptDelete);
    }
    
    return;
}

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
void ProcessSofttimer(uint16 u16CurrentTime)
{
    T_SOFTTIMER_NODE *ptTail;
    uint16 u16DelayTime;
    
    ptTail = sg_ptSofttimerHead->ptNext;
    while (NULL != ptTail)
    {
        u16DelayTime = u16CurrentTime - ptTail->tSofttimer.u16OldTime;
        if (u16DelayTime >= ptTail->tSofttimer.u16Period)  /* Timeup */
        {
            g_aptSofttimerTimeout[ptTail->tSofttimer.u8TaskID] = ptTail->tSofttimer.pfSofttimerCB;
            ptTail->tSofttimer.u16OldTime = u16CurrentTime;
            if (0xffff != ptTail->tSofttimer.u16Count)
            {
                ptTail->tSofttimer.u16Count--;
                if (0 == ptTail->tSofttimer.u16Count)
                {
                    DeleteSofttimer(ptTail->tSofttimer.u8TaskID);
                }
            }
        }
        ptTail = ptTail->ptNext;
    }
    
    return;
}


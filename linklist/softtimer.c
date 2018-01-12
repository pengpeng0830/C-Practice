#include "Public.h"
#include "Softtimer.h"
#include "stdlib.h"
#include "stdio.h"

static T_SOFTTIMER_NODE *sg_ptSofttimerHead = NULL;  /* The head of the linklist */

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
uint8 SofttimerInit(void)
{
    sg_ptSofttimerHead = (T_SOFTTIMER_NODE *)malloc(sizeof(T_SOFTTIMER_NODE));
    if (NULL == sg_ptSofttimerHead)
    {
        return FAULT;
    }
    sg_ptSofttimerHead->ptNext = NULL;
    
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
uint16 CreateSofttimer(T_SOFTTIMER *ptSofttimer)
{
    T_SOFTTIMER_NODE *ptTail,*ptAddSofttimer;

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
    
    while (NULL != ptTail)
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
uint16 DeleteSofttimer(uint8 ucTaskID)
{
    T_SOFTTIMER_NODE *ptTail,*ptDelete;

    ptTail = sg_ptSofttimerHead;
    
    while (NULL != ptTail->ptNext)
    {
        if (ptTail->ptNext->tSofttimer.u8TaskID == ucTaskID)
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
void ProcessSofttimer(uint16 uint16CurrentTime)
{
    T_SOFTTIMER_NODE *ptTail;
    uint16 uint16SetTime;

    ptTail = sg_ptSofttimerHead->ptNext;
    while (NULL != ptTail)
    {
        if (ptTail->tSofttimer.u16Period + ptTail->tSofttimer.u16OldTime > 0xffff)
        {
            uint16SetTime = ptTail->tSofttimer.u16Period + ptTail->tSofttimer.u16OldTime - 0xffff;
        }
        else
        {
            uint16SetTime = ptTail->tSofttimer.u16Period + ptTail->tSofttimer.u16OldTime;
        }
            
        if (uint16SetTime < uint16CurrentTime)  /* Timeup */
        {
            printf("TASK ID:%d timeout",ptTail->tSofttimer.u8TaskID);
            ptTail->tSofttimer.u16OldTime = uint16CurrentTime;
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


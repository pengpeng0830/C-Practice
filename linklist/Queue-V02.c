#include "Public.h"
#include "queue.h"
#include "stdio.h"
#include "stdlib.h"

static T_QUEUE *sg_aptQueuePara[E_QUEUE_CHANNEL_NUM] = NULL;

/******************************************************************************
* Name       : uint16 CreateQueue(T_QUEUE *ptQueuePara)
* Function   : Create a Queue
* Input      : T_QUEUE *ptQueuePara
* Output:    : None
* Return     : FAULT:Create queue failed
*              TRUE: Create queue success
* Description: None
* Version    : V1.00
* Author     : XZP
* Date       : 15th Jan 2018
******************************************************************************/
uint16 CreateQueue(T_QUEUE *ptQueuePara)
{
    if (NULL == ptQueuePara)
    {
        printf("Create Queue Failed!");
        return FAULT;
    }
    if (ptQueuePara->u8ChannelNo >= E_QUEUE_CHANNEL_NUM)
    {
        printf("Create Queue Failed!");
        return FAULT;
    }

    sg_aptQueuePara[ptQueuePara->u8ChannelNo] = ptQueuePara;

    ptQueuePara->pPara = (pvoid *)malloc(ptQueuePara->u8MaxSize * sizeof(pvoid *));
    if (NULL == ptQueuePara->pPara)
    {
        printf("Create Queue Failed!");
        return FAULT;
    }
    ptQueuePara->u8Front = 0;
    ptQueuePara->u8Rear  = 0;
    
    return TRUE;
}

/******************************************************************************
* Name       : uint16 FullQueueCheck(uint8 u8ChannelNo)
* Function   : Check the queue is full or not
* Input      : uint8 u8ChannelNo
* Output:    : None
* Return     : FAULT       :Input u8ChannelNo is error
*              QUEUE_FULL  :Queue is full
*              QUEUE_NOFULL:Queue is not full
* Description: None
* Version    : V1.00
* Author     : XZP
* Date       : 15th Jan 2018
******************************************************************************/
uint16 FullQueueCheck(uint8 u8ChannelNo)
{
    T_QUEUE *ptQueueTemp;
    
    if (E_QUEUE_CHANNEL_NUM <= u8ChannelNo)
    {
        return FAULT;
    }
    
    ptQueueTemp = sg_aptQueuePara[u8ChannelNo];
    if (ptQueueTemp->u8Front == ((ptQueueTemp->u8Rear + 1) % ptQueueTemp->u8MaxSize))
    {
        return QUEUE_FULL;
    }
    return QUEUE_NOFULL;
}

/******************************************************************************
* Name       : uint16 EmptyQueueCheck(uint8 u8ChannelNo)
* Function   : Check the queue is empty or not
* Input      : uint8 u8ChannelNo
* Output:    : None
* Return     : FAULT        :Input u8ChannelNo is error
*              QUEUE_EMPTY  :Queue is empty
*              QUEUE_NOEMPTY:Queue is not empty
* Description: None
* Version    : V1.00
* Author     : XZP
* Date       : 15th Jan 2018
******************************************************************************/
uint16 EmptyQueueCheck(uint8 u8ChannelNo)
{
    T_QUEUE *ptQueueTemp;
    
    if (E_QUEUE_CHANNEL_NUM <= u8ChannelNo)
    {
        return FAULT;
    }
    
    ptQueueTemp = sg_aptQueuePara[u8ChannelNo];
    if (ptQueueTemp->u8Front == ptQueueTemp->u8Rear)
    {
        return QUEUE_EMPTY;
    }
    return QUEUE_NOEMPTY;
}


/******************************************************************************
* Name       : uint16 QueueInput(uint8 u8ChannelNo, pvoid *pPara)
* Function   : Input a para into queue
* Input      : uint8 u8ChannelNo
*              pvoid *pPara:the input para
* Output:    : None
* Return     : FAULT:Input para failed
*              TRUE :Input para success
* Description: None
* Version    : V1.00
* Author     : XZP
* Date       : 15th Jan 2018
******************************************************************************/
uint16 QueueInput(uint8 u8ChannelNo, pvoid *pPara)
{
    T_QUEUE *ptQueueTemp;

    if (u8ChannelNo >= E_QUEUE_CHANNEL_NUM)
    {
        return FAULT;
    }
    if (QUEUE_FULL == FullQueueCheck(u8ChannelNo))
    {
        return FAULT;
    }
    ptQueueTemp = sg_aptQueuePara[u8ChannelNo];
    ptQueueTemp->pPara[ptQueueTemp->u8Rear] = (pvoid)pPara;
    ptQueueTemp->u8Rear = (ptQueueTemp->u8Rear + 1) % ptQueueTemp->u8MaxSize;

    return TRUE;
}

/******************************************************************************
* Name       : uint16 QueueOutput(uint8 u8ChannelNo, pvoid *pPara)
* Function   : Output a para from queue
* Input      : uint8 u8ChannelNo
* Output:    : pvoid *pPara: The output para
* Return     : FAULT:Output para failed
*              TRUE :Output para success
* Description: None
* Version    : V1.00
* Author     : XZP
* Date       : 15th Jan 2018
******************************************************************************/
uint16 QueueOutput(uint8 u8ChannelNo, pvoid *pPara)
{
    T_QUEUE *ptQueueTemp;

    if (E_QUEUE_CHANNEL_NUM <= u8ChannelNo)
    {
        return FAULT;
    }
    if (QUEUE_EMPTY == EmptyQueueCheck(u8ChannelNo))
    {
        return FAULT;
    }
    ptQueueTemp = sg_aptQueuePara[u8ChannelNo];
    *pPara = ptQueueTemp->pPara[ptQueueTemp->u8Front];
    ptQueueTemp->u8Front = (ptQueueTemp->u8Front + 1) % ptQueueTemp->u8MaxSize;

    return TRUE;
}


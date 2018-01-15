#include "Queue.h"

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
    uint8 u8ChannelNo;
    if (NULL == ptQueuePara)
    {
        printf("Create Queue Failed!");
        return FAULT;
    }
    if (E_QUEUE_CHANNEL_NUM <= ptQueuePara->u8ChannelNo)
    {
        printf("Create Queue Failed!");
        return FAULT;
    }

    u8ChannelNo = ptQueuePara->u8ChannelNo;
    sg_aptQueuePara[u8ChannelNo] = ptQueuePara;

    ptQueuePara->pu8Base = (uint8 *)malloc(sizeof(uint8) * ptQueuePara->u8MaxSize);
    if (NULL == ptQueuePara->pu8Base)
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
* Name       : uint16 QueueAddPara(uint8 u8ChannelNo, uint8 u8Para)
* Function   : Add a para into queue
* Input      : uint8 u8ChannelNo
*              uint8 u8Para
* Output:    : None
* Return     : FAULT:Add para failed
*              TRUE :Add para success
* Description: None
* Version    : V1.00
* Author     : XZP
* Date       : 15th Jan 2018
******************************************************************************/
uint16 QueueAddPara(uint8 u8ChannelNo, uint8 u8Para)
{
    T_QUEUE *ptQueueTemp;

    if (E_QUEUE_CHANNEL_NUM <= u8ChannelNo)
    {
        return FAULT;
    }
    if (QUEUE_FULL == FullQueueCheck(u8ChannelNo))
    {
        return FAULT;
    }
    ptQueueTemp = sg_aptQueuePara[u8ChannelNo];
    ptQueueTemp->pu8Base[ptQueueTemp->u8Rear] = u8Para;
    ptQueueTemp->u8Rear = (ptQueueTemp->u8Rear + 1) % ptQueueTemp->u8MaxSize;

    return TRUE;
}

/******************************************************************************
* Name       : uint16 QueueDeletePara(uint8 u8ChannelNo, uint8 u8Para)
* Function   : Delete a para from queue
* Input      : uint8 u8ChannelNo
* Output:    : uint8 *pu8Para: The delete para
* Return     : FAULT:Delete para failed
*              TRUE :Delete para success
* Description: None
* Version    : V1.00
* Author     : XZP
* Date       : 15th Jan 2018
******************************************************************************/
uint16 QueueDeletePara(uint8 u8ChannelNo, uint8 *pu8Para)
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
    (&pu8Para) = ptQueueTemp->pu8Base[ptQueueTemp->u8Front];
    ptQueueTemp->u8Front = (ptQueueTemp->u8Front + 1) % ptQueueTemp->u8MaxSize;

    return TRUE;
}


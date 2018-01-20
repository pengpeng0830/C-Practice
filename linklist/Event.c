#include "Public.h"
#include "queue.h"
#include "Event.h"

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
uint16 EventInit(T_QUEUE *ptQueuePara)
{
    ptQueuePara->u8ChannelNo = E_QUEUE_EVENT;
    return CreateQueue(ptQueuePara);
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
uint16 EmptyEventCheck(void)
{
    return EmptyQueueCheck(E_QUEUE_EVENT);
}

/******************************************************************************
* Name       : uint16 QueueInput(uint8 u8ChannelNo, uint8 u8Para)
* Function   : Input a para into queue
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
uint16 EventSet(pvoid *pPara)
{
    return QueueInput(E_QUEUE_EVENT,pPara);
}

/******************************************************************************
* Name       : uint16 QueueOutput(uint8 u8ChannelNo, uint8 *pu8Para)
* Function   : Output a para from queue
* Input      : uint8 u8ChannelNo
* Output:    : uint8 *pu8Para: The delete para
* Return     : FAULT:Delete para failed
*              TRUE :Delete para success
* Description: None
* Version    : V1.00
* Author     : XZP
* Date       : 15th Jan 2018
******************************************************************************/
uint16 EventGet(pvoid *pPara)
{
    return QueueOutput(E_QUEUE_EVENT,pPara);
}

/******************************************************************************
* Name       : uint16 QueueOutput(uint8 u8ChannelNo, uint8 *pu8Para)
* Function   : Output a para from queue
* Input      : uint8 u8ChannelNo
* Output:    : uint8 *pu8Para: The delete para
* Return     : FAULT:Delete para failed
*              TRUE :Delete para success
* Description: None
* Version    : V1.00
* Author     : XZP
* Date       : 15th Jan 2018
******************************************************************************/
uint16 EventProcess(void)
{
    PF_EVENT_CB Event_CB;
    if (QUEUE_NOEMPTY == EmptyEventCheck())
    {
        EventGet((pvoid *)Event_CB);
        Event_CB();
    }
    return TRUE;
}


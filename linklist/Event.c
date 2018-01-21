#include "Public.h"
#include "queue.h"
#include "Event.h"

/******************************************************************************
* Name       : uint16 EventInit(T_QUEUE *ptEventPara)
* Function   : Create a event queue
* Input      : T_QUEUE *ptEventPara
* Output:    : None
* Return     : FAULT:Create event failed
*              TRUE: Create event success
* Description: None
* Version    : V1.00
* Author     : XZP
* Date       : 15th Jan 2018
******************************************************************************/
uint16 EventInit(T_QUEUE *ptEventPara)
{
    ptEventPara->u8ChannelNo = E_QUEUE_EVENT;
    return CreateQueue(ptEventPara);
}

/******************************************************************************
* Name       : uint16 EmptyEventCheck(void)
* Function   : Check the event queue is empty or not
* Input      : None
* Output:    : None
* Return     : QUEUE_EMPTY  :Queue is empty
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
* Name       : uint16 EventSet(pvoid *pPara)
* Function   : Input a event into queue
* Input      : pvoid *pPara
* Output:    : None
* Return     : FAULT:Input event failed
*              TRUE :Input event success
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
* Name       : uint16 EventGet(pvoid *pPara)
* Function   : Output a event from queue
* Input      : None
* Output:    : pvoid *pPara
* Return     : FAULT:Output event failed
*              TRUE :Output event success
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
* Name       : void EventProcess(void)
* Function   : Process event
* Input      : None
* Output:    : None
* Return     : None
* Description: None
* Version    : V1.00
* Author     : XZP
* Date       : 15th Jan 2018
******************************************************************************/
void EventProcess(void)
{
    PF_EVENT_CB Event_CB;
    if (QUEUE_NOEMPTY == EmptyEventCheck())
    {
        EventGet((pvoid *)(&Event_CB));
        Event_CB();
    }
    return;
}


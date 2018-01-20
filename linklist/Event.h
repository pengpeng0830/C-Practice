#ifndef __EVENT_H
#define __EVENT_H

typedef uint32 (*PF_EVENT_CB)(void);

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
uint16 EventInit(T_QUEUE *ptQueuePara);

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
uint16 EmptyEventCheck(void);

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
uint16 EventSet(pvoid *pPara);

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
uint16 EventGet(pvoid *pPara);

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
uint16 EventProcess(void);

#endif

/****************************END OF FILE*********************************/

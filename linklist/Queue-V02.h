#ifndef __QUEUE_H
#define __QUEUE_H

#define QUEUE_NOFULL   (0)
#define QUEUE_FULL     (1)

#define QUEUE_NOEMPTY  (0)
#define QUEUE_EMPTY    (1)

typedef struct Queue   
{  
    pvoid *pPara;      /* 指向分配的内存                   */
    uint8 u8ChannelNo; /* 通道号                           */
    uint8 u8Front;     /* 指向队列第一个元素               */
    uint8 u8Rear;      /* 指向队列最后一个元素的下一个元素 */
    uint8 u8MaxSize;   /* 循环队列的最大存储空间           */
}T_QUEUE;  

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
uint16 CreateQueue(T_QUEUE *ptQueuePara);

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
uint16 FullQueueCheck(uint8 u8ChannelNo);

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
uint16 EmptyQueueCheck(uint8 u8ChannelNo);

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
uint16 QueueInput(uint8 u8ChannelNo, pvoid *pPara);

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
uint16 QueueOutput(uint8 u8ChannelNo, pvoid *pPara);

#endif

/****************************END OF FILE*********************************/

#include "Public.h"
#include "queue.h"
#include "sem.h"

#define BINARY_SEM_FULL     (1)
#define BINARY_SEM_EMPTY    (0)

/******************************************************************************
* Name       : pvoid *CreateBinarySem(T_QUEUE *ptSemPara)
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
pvoid *CreateBinarySem(T_QUEUE *ptSemPara)
{
    ptSemPara->u8MaxSize = 1;
    return CreateQueue(ptSemPara);
}

/******************************************************************************
* Name       : uint16 GetBinarySem(uint8 u8ChannelNo)
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
uint16 GetBinarySem(uint8 u8ChannelNo)
{
    T_QUEUE *ptQueueTemp;
    uint8 u8Test = 0;
        
    if (u8ChannelNo >= E_QUEUE_CHANNEL_NUM)
    {
        return FAULT;
    }
    if (QUEUE_EMPTY == EmptyQueueCheck(u8ChannelNo))
    {
        return FAULT;
    }
    else
    {
        QueueOutput(u8ChannelNo,(pvoid *)(&u8Test));
    }
    return BINARY_SEM_FULL;
}

/******************************************************************************
* Name       : uint16 SetBinarySem(uint8 u8ChannelNo)
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
uint16 SetBinarySem(uint8 u8ChannelNo)
{
    T_QUEUE *ptQueueTemp;
    uint8 u8Test = 0;
        
    if (u8ChannelNo >= E_QUEUE_CHANNEL_NUM)
    {
        return FAULT;
    }
    if (QUEUE_FULL == FullQueueCheck(u8ChannelNo))
    {
        return FAULT;
    }
    else
    {
        QueueInput(u8ChannelNo,(pvoid *)(&u8Test));
    }
    return BINARY_SEM_EMPTY;
}



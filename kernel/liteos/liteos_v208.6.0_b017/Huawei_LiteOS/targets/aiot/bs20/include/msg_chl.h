/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: msg adapter \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-04-10, Create file. \n
 */
#ifndef _MSG_CHL_H_
#define _MSG_CHL_H_

#include "los_base.h"
#ifdef LOSCFG_COMPAT_CMSIS
#include "cmsis_os2.h"
#endif

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cpluscplus */
#endif /* __cpluscplus */

#define LOS_MSG_CHL_NAME_MAX_LEN                16

typedef void *osMsgChlId_t;

typedef struct tagMsgChl {
    LOS_DL_LIST stList;
    CHAR *pcChlName;
    osMsgChlId_t MsgChlID;
}LOS_MSG_CHL_CTL_T;


/*****************************************************************************
 Function    : LOS_MsgChl_Init
 Description : inilization the Message channel
 Input       : None
 Output      : None
 Return      : None
 *****************************************************************************/
VOID LOS_MsgChl_Init(VOID);


/*****************************************************************************
 Function    : LOS_MsgChl_Open
 Description : Open a message channel by name
 Input       : const CHAR *pcMsgChlName
 Output      : None
 Return      : osMsgChlId_t or NULL
 *****************************************************************************/
osMsgChlId_t LOS_MsgChl_Open(const CHAR *pcMsgChlName);


/*****************************************************************************
 Function    : LOS_MsgChl_Delete
 Description : Delete a message channle
 Input       : osMsgChlId_t MsgChlID: Message Channel ID get by call LOS_MsgChl_Open or LOS_MsgChl_GetChlbyName
 Output      : None
 Return      : None
 *****************************************************************************/
VOID LOS_MsgChl_Delete(osMsgChlId_t MsgChlID);


/*****************************************************************************
 Function    : LOS_MsgChl_GetChlbyName
 Description : Get a message channle by name
 Input       : const char *pcMsgChlName: name of message channel.
 Output      : None
 Return      : osMsgChlId_t :SUCCESS; NULL: FAIL
 *****************************************************************************/
osMsgChlId_t LOS_MsgChl_GetChlbyName(const char *pcMsgChlName);

/*****************************************************************************
 Function    : LOS_MsgChl_Write
 Description : write data to message channel
 Input       : osMsgChlId_t MsgChlID: Message Channel ID get by call
               VOID         *pData  : Data to write in MsgChl; The memory of Data must be malloc by Write.
               UINT32 timeout       : ms. osNoWait/osWaitForever write timeout time
 Output      : None
 Return      : LOS_OK: SUCCESS; LOS_NOK: FAIL
 *****************************************************************************/
UINT32 LOS_MsgChl_Write(osMsgChlId_t MsgChlID, VOID *pData, UINT32 timeout);


/*****************************************************************************
 Function    : LOS_MsgChl_Read
 Description : read data from a messaeg channel.
 Input       : osMsgChlId_t     MsgChlID: Message Channel ID get by call
               VOID         **ppMsgBuf  : the address of the point to save the buff address,
                                          the buff memory must be free by caller.
               UINT32           timeout : CMSIS_RTOS_TimeOutValue or 0 in case of no time-out
 Output      : None
 Return      : LOS_OK: SUCCESS; LOS_NOK: FAIL
 *****************************************************************************/
UINT32 LOS_MsgChl_Read(osMsgChlId_t MsgChlID, VOID **ppMsgBuf, UINT32 timeout);

/*****************************************************************************
 Function    : LOS_MsgChl_GetCount
 Description : Get message count by ID
 Input       : osMsgChlId_t MsgChlID: Message Channel ID get by call LOS_MsgChl_Open or LOS_MsgChl_GetChlbyName
 Output      : Msg Count
 Return      : osMsgChlId_t :Count; NULL: FAIL
 *****************************************************************************/
UINT32 LOS_MsgChl_GetCount(osMsgChlId_t MsgChlID);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */

#endif

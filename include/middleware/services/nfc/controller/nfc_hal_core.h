/**
 * Copyright (c) @CompanyNameMagicTag 2021. All rights reserved. \n
 * Description: nfc hal core \n
 * Author: @CompanyNameTag \n
 * Date: 2021-08-20 \n
 */
/** @defgroup middleware_service_nfc_controller_hal_core NFC HAL Core
 * @ingroup middleware_service_nfc_controller
 * @{
 */
#ifndef NFC_HAL_CORE_H
#define NFC_HAL_CORE_H

#include <stdint.h>
#include <stdbool.h>
#include "nfc_error_code.h"
#include "nfc_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef HAVE_NFC_LISTEN
/**
 * @if Eng
 * @brief  Callback for upper layer to handle HCI message from NFCEE.
 * @param  [in]     buff  buffer for storing HCI message wrapped in NCI packet.
 * @param  [in]     len  data length in buffer.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  上层注册的回调函数，用于处理从NFCEE过来的HCI命令或通知。
 * @param  [in]     buff  有NCI包封装的HCI信息的存储地址。
 * @param  [in]     len  封装的总数据字节长度。
 * @retval NFC_OK   成功。
 * @retval Other    失败。参考 @ref NfcErrorCode 。
 * @endif
 */
typedef NfcErrorCode (*FuncProcessHciFromNfcee)(uint8_t *buff, uint16_t len);
#endif

/**
 * @if Eng
 * @brief  NFC HAL core parameters structure.
 * @else
 * @brief  NFC硬件抽象层核心参数结构体。
 * @endif
 */
typedef struct NfcHalCoreParamsStruct {
    /** @if Eng  NCI control packet read operation timeout in millisecond.
     *  @else    NCI控制包读操作超时，单位毫秒。
     *  @endif */
    uint32_t readTimeout;
    /** @if Eng  NCI data packet read operation timeout in millisecond.
     *  @else    NCI数据包读操作超时，单位毫秒。
     *  @endif */
    uint32_t dataTimeout;
#ifdef HAVE_NFC_LISTEN
    /** @if Eng  Callback to handle HCI message from NFCEE. For details, see @ref FuncProcessHciFromNfcee.
     *  @else    上层注册的回调函数，用于处理从NFCEE过来的HCI命令或通知。参考 @ref FuncProcessHciFromNfcee 。
     *  @endif */
    FuncProcessHciFromNfcee processHciFromNfcee;
#endif
} NfcHalCoreParams;

#ifdef HAVE_NFC_POLL
#pragma pack(push, 1)
/**
 * @if Eng
 * @brief  NFC HAL T3T polling notification parameters structure.
 * @else
 * @brief  NFC硬件抽象层T3T轮询通知参数结构体。
 * @endif
 */
typedef struct NfcHalT3tPollNtfParamsStruct {
    /** @if Eng  NFCID2 array. For length, see @ref NFCID2_LEN.
     *  @else    NFCID2的存储数组。长度参考 @ref NFCID2_LEN 。
     *  @endif */
    uint8_t nfcid2[NFCID2_LEN];
    /** @if Eng  PAD0 parameter array. For length, see @ref T3T_PAD0_LEN.
     *  @else    PAD0的存储数组。长度参考 @ref T3T_PAD0_LEN 。
     *  @endif */
    uint8_t pad0[T3T_PAD0_LEN];
    /** @if Eng  PAD1 parameter array. For length, see @ref T3T_PAD1_LEN.
     *  @else    PAD1的存储数组。长度参考 @ref T3T_PAD1_LEN 。
     *  @endif */
    uint8_t pad1[T3T_PAD1_LEN];
    /** @if Eng  MRTI-check parameter.
     *  @else    MRTI-check参数。
     *  @endif */
    uint8_t mrtiCheck;
    /** @if Eng  MRTI-update parameter.
     *  @else    MRTI-update参数。
     *  @endif */
    uint8_t mrtiUpdate;
    /** @if Eng  PAD2 parameter.
     *  @else    PAD2参数。
     *  @endif */
    uint8_t pad2;
    /** @if Eng  RD parameter array. For length, see @ref T3T_RD_LEN.
     *  @else    RD的存储数组。长度参考 @ref T3T_RD_LEN 。
     *  @endif */
    uint8_t rd[T3T_RD_LEN];
} NfcHalT3tPollNtfParams;
#pragma pack(pop)

/**
 * @if Eng
 * @brief  NFC HAL T3T sense responses structure.
 * @else
 * @brief  NFC硬件抽象层T3T轮询感应回复参数结构体。
 * @endif
 */
typedef struct NfcHalT3tSensfResStruct {
    /** @if Eng  T3T polling notification parameters array. For details, see @ref NfcHalT3tPollNtfParams.
     *  @else    T3T轮询感应通知结构体数组。元素结构体参考 @ref NfcHalT3tPollNtfParams 。
     *  @endif */
    NfcHalT3tPollNtfParams resParams[T3T_POLL_SENSF_RES_MAX_SIZE];
    /** @if Eng  The number of received T3T polling notification parameters.
     *  @else    接收到的T3T轮询感应通知个数。
     *  @endif */
    uint8_t resNum;
} NfcHalT3tSensfRes;

/**
 * @if Eng
 * @brief  NFC HAL T3T polling command parameters structure.
 * @else
 * @brief  NFC硬件抽象层T3T轮询命令参数结构体。
 * @endif
 */
typedef struct NfcHalT3tPollCmdParamsStruct {
    /** @if Eng  The system code of T3T polling command.
     *  @else    T3T轮询命令的系统码。
     *  @endif */
    uint16_t sc;
    /** @if Eng  The request code of T3T polling command.
     *  @else    T3T轮询命令的请求码。
     *  @endif */
    uint8_t rc;
    /** @if Eng  The time slot number of T3T polling command.
     *  @else    T3T轮询命令的时隙个数。
     *  @endif */
    uint8_t tsn;
    /** @if Eng  The time in millisecond to wait fot T3T polling notification.
     *  @else    T3T轮询等待响应通知的超时时间，单位毫秒。
     *  @endif */
    uint16_t timeout;
} NfcHalT3tPollCmdParams;
#endif

/**
 * @if Eng
 * @brief  NFC technology A parameters structure.
 * @else
 * @brief  NFC技术A的参数结构体。
 * @endif
 */
typedef struct {
    /** @if Eng  Sense response array. For length, see @ref SENS_RES_LEN.
     *  @else    技术A的轮询感应回复。长度参考 @ref SENS_RES_LEN 。
     *  @endif */
    uint8_t sensRes[SENS_RES_LEN];
    /** @if Eng  The length of NFCID1.
     *  @else    NFCID1的长度。
     *  @endif */
    uint8_t nfcid1Len;
    /** @if Eng  NFCID1 buffer. For buffer max length, see @ref NFCID1_MAX_LEN.
     *  @else    NFCID1的存储空间。最大长度参考 @ref NFCID1_MAX_LEN 。
     *  @endif */
    uint8_t nfcid1[NFCID1_MAX_LEN];
    /** @if Eng  Select response.
     *  @else    技术A的选择回复。
     *  @endif */
    uint8_t selRes;
} NfcTechAParams;

/**
 * @if Eng
 * @brief  NFC technology B parameters structure.
 * @else
 * @brief  NFC技术B的参数结构体。
 * @endif
 */
typedef struct {
    /** @if Eng  The length of senseB response.
     *  @else    技术B的轮询感应回复长度。
     *  @endif */
    uint8_t sensbResLen;
    /** @if Eng  SenseB response buffer. First 4 bytes are NFCID0. For buffer max length, see @ref SENSB_RES_MAX_LEN.
     *  @else    技术B的轮询感应回复长度。头部4个字节是NFCID0。存储最大长度参考 @ref SENSB_RES_MAX_LEN 。
     *  @endif */
    uint8_t sensbRes[SENSB_RES_MAX_LEN];
} NfcTechBParams;

/**
 * @if Eng
 * @brief  NFC technology F parameters structure.
 * @else
 * @brief  NFC技术F的参数结构体。
 * @endif
 */
typedef struct {
    /** @if Eng  Technology F Bit rate.
     *  @else    技术F的速率。
     *  @endif */
    uint8_t bitRate;
    /** @if Eng  The length of senseF response.
     *  @else    技术F的轮询感应回复长度。
     *  @endif */
    uint8_t sensfResLen;
    /** @if Eng  SenseF response buffer. First 8 bytes are NFCID2. For buffer max length, see @ref SENSF_RES_MAX_LEN.
     *  @else    技术F的轮询感应回复长度。头部8个字节是NFCID2。存储最大长度参考 @ref SENSF_RES_MAX_LEN 。
     *  @endif */
    uint8_t sensfRes[SENSF_RES_MAX_LEN];
} NfcTechFParams;

/**
 * @if Eng
 * @brief  NFC technology V parameters structure.
 * @else
 * @brief  NFC技术V的参数结构体。
 * @endif
 */
typedef struct {
    /** @if Eng  Response Flag.
     *  @else    回复的标记字节信息。
     *  @endif */
    uint8_t resFlag;
    /** @if Eng  DSFID parameter.
     *  @else    DSFID参数信息。
     *  @endif */
    uint8_t dsfid;
    /** @if Eng  UID buffer. For buffer length, see @ref UID_LEN.
     *  @else    UID信息。长度参考 @ref UID_LEN 。
     *  @endif */
    uint8_t uid[UID_LEN];
} NfcTechVParams;

/**
 * @if Eng
 * @brief  NFC technology parameters union.
 * @else
 * @brief  NFC技术的参数联合体。
 * @endif
 */
typedef union {
    /** @if Eng  Technology A parameters. For details, see @ref NfcTechAParams.
     *  @else    技术A的参数信息。参考 @ref NfcTechAParams 。
     *  @endif */
    NfcTechAParams a;
    /** @if Eng  Technology B parameters. For details, see @ref NfcTechBParams.
     *  @else    技术B的参数信息。参考 @ref NfcTechBParams 。
     *  @endif */
    NfcTechBParams b;
    /** @if Eng  Technology F parameters. For details, see @ref NfcTechFParams.
     *  @else    技术F的参数信息。参考 @ref NfcTechFParams 。
     *  @endif */
    NfcTechFParams f;
    /** @if Eng  Technology V parameters. For details, see @ref NfcTechVParams.
     *  @else    技术V的参数信息。参考 @ref NfcTechVParams 。
     *  @endif */
    NfcTechVParams v;
} NfcTechParams;

/**
 * @if Eng
 * @brief  NFC interface activation information structure.
 * @else
 * @brief  NFC接口激活信息结构体。
 * @endif
 */
typedef struct {
    /** @if Eng  NCI interface. For details, see @ref NFC_NCI_RF_INTERFACE_ENUM.
     *  @else    NCI接口。参考 @ref NFC_NCI_RF_INTERFACE_ENUM 。
     *  @endif */
    uint8_t interface;
    /** @if Eng  NCI protocol. For details, see @ref NFC_NCI_RF_PROTOCOL_ENUM.
     *  @else    NCI协议。参考 @ref NFC_NCI_RF_PROTOCOL_ENUM 。
     *  @endif */
    uint8_t protocol;
    /** @if Eng  NCI technology mode. For details, see @ref NFC_NCI_RF_TECH_MODE_ENUM.
     *  @else    NCI技术模式。参考 @ref NFC_NCI_RF_TECH_MODE_ENUM 。
     *  @endif */
    uint8_t techMode;
    /** @if Eng  NFC technology parameters union. For details, see @ref NfcTechParams.
     *  @else    NFC技术的参数联合体。参考 @ref NfcTechParams 。
     *  @endif */
    NfcTechParams techParams;
} NfcIntfActInfo;

/**
 * @if Eng
 * @brief  Clean up all NCI messages from device.
 * @else
 * @brief  清理掉从芯片端发来的所有NCI消息。
 * @endif
 */
void NFC_HAL_CleanUpDevice(void);

/**
 * @if Eng
 * @brief  Send NCI command and receive response.
 * @param  [in]     buf  Data buffer to send.
 * @param  [in]     count  Data length to send.
 * @param  [out]    recvRsp  Buffer to receive response.
 * @param  [in,out] rspLen  Input value is receive buffer max length, output value is actual response length.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  发送NCI命令并接收回复。
 * @param  [in]     buf  发送数据。
 * @param  [in]     count  发送数据长度。
 * @param  [out]    recvRsp  接收回复存储地址。
 * @param  [in,out] rspLen  输入为接收存储空间的大小，输出为真实接收到的回复字节长度。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_SendNciCmdAndRecvRsp(uint8_t *buf, uint16_t count, uint8_t *recvRsp, uint16_t *rspLen);

/**
 * @if Eng
 * @brief  Set NFC HAL core module parameters.
 * @param  [in]     params  Core parameters structure pointer. For details, see @ref NfcHalCoreParams.
 * @else
 * @brief  设置NFC硬件抽象层核心参数。
 * @param  [in]     params  核心参数。参考 @ref NfcHalCoreParams 。
 * @endif
 */
void NFC_HAL_SetCoreParams(NfcHalCoreParams *params);

/**
 * @if Eng
 * @brief  Open NFC HAL layer, which triggers FW loading for NFC chip.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  打开NFC HAL层，触发芯片上电加载。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_Open(void);

/**
 * @if Eng
 * @brief  Close NFC HAL layer, which powers off NFC chip.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  关闭NFC HAL层，芯片下电。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_Close(void);

/**
 * @if Eng
 * @brief  NCI reset operation according to NCI specification.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  NCI协议定义的复位操作。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_NciReset(void);

/**
 * @if Eng
 * @brief  NCI initialization operation according to NCI specification.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  NCI协议定义的初始化操作。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_NciInit(void);

/**
 * @if Eng
 * @brief  NCI set config operation according to NCI specification.
 * @param  [in]     cmd  NCI set config command buffer to send.
 * @param  [in]     len  NCI set config command length.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  NCI协议定义的配置参数操作。
 * @param  [in]     cmd  NCI配置参数命令。
 * @param  [in]     len  NCI配置参数命令字节长度。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_NciSetConfig(uint8_t *cmd, uint16_t len);

/**
 * @if Eng
 * @brief  NCI set discovery map operation according to NCI specification.
 * @param  [in]     cmd  NCI RF discover map command to send.
 * @param  [in]     len  NCI RF discover map command length.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  NCI协议定义的设置RF接口映射关系操作。
 * @param  [in]     cmd  NCI RF接口映射配置命令。
 * @param  [in]     len  NCI RF接口映射配置命令字节长度。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_NciDiscovMap(uint8_t *cmd, uint16_t len);

/**
 * @if Eng
 * @brief  NCI start discovery operation according to NCI specification.
 * @param  [in]     cmd  NCI discovery command to send.
 * @param  [in]     len  NCI discovery command length.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  NCI协议定义的设置RF接口映射关系操作。
 * @param  [in]     cmd  NCI开启轮询发现命令。
 * @param  [in]     len  NCI开启轮询发现命令字节长度。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_NciStartDiscovery(uint8_t *cmd, uint16_t len);

/**
 * @if Eng
 * @brief  Start NFC discovery with input technology mode list.
 * @param  [in]     techModeList  Technology mode list for discovery.
 * @param  [in]     num  The number of items in technology mode list.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  根据输入的技术模式，开启RF轮询发现流程。
 * @param  [in]     techModeList  技术模式列表用于轮询发现。
 * @param  [in]     num  输入技术模式的个数。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_StartDiscovery(uint8_t *techModeList, uint8_t num);

/**
 * @if Eng
 * @brief  Receive one NCI packet (including NCI head) with indicated timeout.
 * @param  [out]    buff  Buffer to receive NCI packet.
 * @param  [in,out] len  Input as buffer size, output as received length.
 * @param  [in]     timeout  Timeout in millisecond to break waiting for read.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  阻塞式接收一个NCI包，会根据输入超时时间退出等待。
 * @param  [out]    buff  接收NCI包的存储地址。
 * @param  [in,out] len  输入时是存储空间大小，输出时是真实接收到的数据长度。
 * @param  [in]     timeout  退出等待的超时时间，单位毫秒。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_ReceiveNciPkt(uint8_t *buff, uint16_t *len, uint32_t timeout);

/**
 * @if Eng
 * @brief  Send NFC data.
 * @param  [in]     buf  Data buffer to send.
 * @param  [in]     sendLen  Data length to send.
 * @param  [in]     conn  Logical connection id in which to send data. For details, see @ref NCI_LOGIC_CONN_ID_ENUM.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  发送NFC数据。
 * @param  [in]     buf  发送数据。
 * @param  [in]     sendLen  发送数据长度。
 * @param  [in]     conn  用于发送数据的逻辑管道号。参考 @ref NCI_LOGIC_CONN_ID_ENUM 。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_SendData(uint8_t *buf, uint16_t sendLen, uint8_t conn);

/**
 * @if Eng
 * @brief  Receive unchained nfc data (including handling NCI credit ntf).
 * @param  [out]    recvBuff  Buffer to receive data.
 * @param  [in,out] buffLen  Input as buffer size, output as received data length.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  接收NFC数据，同时处理掉附带的NCI流控通知。
 * @param  [out]    recvBuff  接收数据的存储空间。
 * @param  [in,out] buffLen  输入为存储空间大小，输出为接收到的数据长度。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_RecvUnchainedData(uint8_t *recvBuff, uint16_t *buffLen);

/**
 * @if Eng
 * @brief  Send nfc data and receive unchained nfc data (including handling NCI credit ntf).
 * @param  [in]     sendBuff  Data buffer to send.
 * @param  [in]     lenIn  Data length to send.
 * @param  [in]     conn  Connection id for data to send. For details, see @ref NCI_LOGIC_CONN_ID_ENUM.
 * @param  [out]    recvBuff  Buffer to receive data.
 * @param  [in,out] lenOut  Input as receive buffer size, output as actual received data length.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  发送NFC数据，并接收NFC回复数据，同时处理掉附带的NCI流控通知。
 * @param  [in]     sendBuff  待发送的数据。
 * @param  [in]     lenIn  待发送数据长度。
 * @param  [in]     conn  数据发送所在的逻辑管道号。参考 @ref NCI_LOGIC_CONN_ID_ENUM 。
 * @param  [out]    recvBuff  接收数据的存储空间。
 * @param  [in,out] lenOut  输入为接收数据存储空间最大长度，输出为接收到的数据的真实长度。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_TranceiveUnchainedData(uint8_t *sendBuff, uint16_t lenIn, uint8_t conn,
                                            uint8_t *recvBuff, uint16_t *lenOut);

/**
 * @if Eng
 * @brief  NFC deactivate to idle state operation.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  NFC去激活到空闲状态。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_Deactivate(void);

/**
 * @if Eng
 * @brief  Make NFC device enter idle sleep state and not do any business.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  让NFC设备进入空闲低功耗状态，不做任何业务。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_EnterIdleSleep(void);

/**
 * @if Eng
 * @brief  Config NFC low power feature enable/disable status.
 * @param  [in]     status  Set low power status, enabled or not.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  让NFC设备进入空闲低功耗状态，不做任何业务。
 * @param  [in]     status  低功耗设置状态，是否启用。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_CfgLowPwr(bool status);

#ifdef HAVE_NFC_POLL
/**
 * @if Eng
 * @brief  NCI Iso-Dep NAK presence check according to NCI specification.
 * @param  [out]    isPresent  Presence check result, is present or not.
 * @param  [in]     timeout  Maximum wait time in millisecond for check notifiation.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  NCI协议定义的使用Iso-Dep NAK方法做卡片的在位检测。
 * @param  [out]    isPresent  卡片是否在近场。
 * @param  [in]     timeout  等待检测通知的最长时间，单位毫秒。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_NciIsoDepNakPresenceCheck(bool *isPresent, uint16_t timeout);

/**
 * @if Eng
 * @brief  Receive interface activation notification for Poll mode.
 * @param  [in]     priority  Priority to select which device if find more. \n
 *                            For details, see @ref NFC_CARD_SELECT_PRIORITY_ENUM.
 * @param  [out]    recvNtf  Receive buffer for interface activation notification.
 * @param  [in]     len  Receive buffer size.
 * @param  [in]     timeout  Maximum wait time in millisecond for interface activation notification.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  在Poll模式下接收接口激活通知。
 * @param  [in]     priority  若有多个对端设备的情况下，根据哪个优先级来选择其中一个设备自动做激活。\n
 *                            参考 @ref NFC_CARD_SELECT_PRIORITY_ENUM 。
 * @param  [out]    recvNtf  接收通知的存储空间。
 * @param  [in]     len  存储空间大小。
 * @param  [in]     timeout  等待接口激活通知的最长时间，单位毫秒。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_PollRecvIntfActNtf(uint8_t priority, uint8_t *recvNtf, uint16_t len, uint32_t timeout);

/**
 * @if Eng
 * @brief  Parse interface activation notification for Poll mode.
 * @param  [out]    intfActInfo  Structure buffer to store parsed interface activation notification information.
 * @param  [in]     recvNtf  Receive buffer storing interface activation notification.
 * @param  [in]     len  The length of received interface activation notification.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  在Poll模式下解析出接口激活通知里的信息。
 * @param  [out]    intfActInfo  用于存储解析出来的接口激活通知信息的结构体。
 * @param  [in]     recvNtf  接收到的接口激活通知。
 * @param  [in]     len  接收到的接口激活通知的字节长度。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_PollParseIntfActNtf(NfcIntfActInfo *intfActInfo, uint8_t *recvNtf, uint16_t len);

/**
 * @if Eng
 * @brief  Start continuous Polling field.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  开启连续的发场。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_StartPollField(void);

/**
 * @if Eng
 * @brief  Stop Polling field.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  关闭发场。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_StopPollField(void);

/**
 * @if Eng
 * @brief  Start NFC T3T polling and get polling notifications from nearby NFC devices.
 * @param  [in]     cmdParams  The structure storing T3T polling command parameters.
 * @param  [out]    ntfParams  The structure to store received polling notifications.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  开启T3T轮询检测并获取轮询响应结果。
 * @param  [in]     cmdParams  带有T3T轮询命令参数的结构体。
 * @param  [out]    ntfParams  存储接收到的轮询响应通知的结构体。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_NciT3TPolling(NfcHalT3tPollCmdParams *cmdParams, NfcHalT3tSensfRes *ntfParams);
#endif // HAVE_NFC_POLL

#ifdef HAVE_NFC_LISTEN
/**
 * @if Eng
 * @brief  Start NFCEE discovery and receive available NFCEE list.
 * @param  [out]    nfceeList  The list of discoverred NFCEEs.
 * @param  [in]     size  The maximum number of NFCEEs that can be stored in the NFCEE list.
 * @param  [out]    num  The number of dicoverred NFCEEs in NFCEE list.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  开启NFCEE发现流程并返回接收到的NFCEE列表。
 * @param  [out]    nfceeList  用于存储发现的多个NFCEE的列表。
 * @param  [in]     size  列表最多可存储的NFCEE数目。
 * @param  [out]    num  实际发现的NFCEE个数。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_NfceeDiscovery(uint8_t *nfceeList, uint8_t size, uint8_t *num);

/**
 * @if Eng
 * @brief  Enable NFCEE and get corresponding technology mode list from received RF discovery request notifications.
 * @param  [in]     nfceeId  NFCEE id to enable.
 * @param  [out]    techModeList  The list to store technology modes from RF discovery request notifications.
 * @param  [in]     size  The maximum number of technology modes that can be stored in the NFCEE list.
 * @param  [out]    num  The number of technology modes in technology mode list.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  开启NFCEE的激活流程，从NFCEE接收到的RF轮询请求通知中解析出技术模式的列表并返回。
 * @param  [in]     nfceeId  需要激活的NFCEE ID值。
 * @param  [out]    techModeList  用于存储返回的技术模式信息的数组。
 * @param  [in]     size  最多可存储的技术模式的数目。
 * @param  [out]    num  返回的真实存储的技术模式的个数。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_NfceeEnable(uint8_t nfceeId, uint8_t *techModeList, uint8_t size, uint8_t *num);

/**
 * @if Eng
 * @brief  Set listen route table for NFCC.
 * @param  [in]     cmd  Listen route table command.
 * @param  [in]     len  Command length.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  设置侦听路由表。
 * @param  [in]     cmd  侦听路由表的配置命令。
 * @param  [in]     len  命令长度。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_SetListenRouteTbl(uint8_t *cmd, uint16_t len);

/**
 * @if Eng
 * @brief  Restore HCI RAM information for one NFCEE on reboot to avoid unnecessary session initialization \n
 *         during the first time of activation of the same NFCEE.
 * @param  [in]     cmd  Command buffer with HCI RAM information starting from address = cmd + 3. \n
 *                       The header 3 bytes are reserved for filling NCI header inside this function. \n
 *                       The HCI RAM information get be got from function @ref NFC_HAL_GetHciRam. \n
 *                       The first byte of HCI RAM information is NFCEE id.
 * @param  [in]     len  HCI RAM information length.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  恢复HCI RAM里的信息从而避免重启时对同一个NFCEE首次激活时候做不必要的会话初始化操作。
 * @param  [in]     cmd  恢复HCI RAM信息的配置命令。注意命令内容从cmd + 3位置开始，头部3字节预留给调用函数填充NCI头。 \n
 *                       HCI RAM信息可以从函数 @ref NFC_HAL_GetHciRam 获取，并且首字节为对应的NFCEE ID。
 * @param  [in]     len  从cmd + 3位置开始计算的恢复HCI RAM信息命令的字节长度。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_RestoreHciRam(uint8_t *cmd, uint16_t len);

/**
 * @if Eng
 * @brief  Get HCI RAM information from NFCC and then can save it on DH side.
 * @param  [in]     nfceeId  NFCEE id from which to get HCI RAM information.
 * @param  [out]    buff  Receive buffer to store the total NCI packet containing HCI RAM information. \n
 *                        Valid buff content: 3 bytes of NCI header + 1 byte of Status + X bytes of HCI RAM info. \n
 *                        The caller shall save the X bytes of HCI RAM info into a file. \n
 *                        On next reboot, we can restore HCI RAM info by function @ref NFC_HAL_RestoreHciRam.
 * @param  [in,out] len  Input value as buff size, output value as received total NCI packet length.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  获取某个NFCEE对应的HCI RAM的信息。
 * @param  [in]     nfceeId  需要获取HCI RAM信息的NFCEE ID。
 * @param  [out]    buff  用于存储含有HCI RAM信息的一个完整NCI包的存储空间。 \n
 *                        有效的buff内容: 3字节的NCI头 + 1字节的NFCEE id + X字节的HCI RAM信息。 \n
 *                        调用者要把这X字节的HCI RAM信息保存到文件中，重启时可调用函数 @ref NFC_HAL_RestoreHciRam 恢复数据。
 * @param  [in,out] len  输入为buff的总大小，输出为接收到的完整NCI包的长度。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_GetHciRam(uint8_t nfceeId, uint8_t *buff, uint16_t *len);
#endif // HAVE_NFC_LISTEN

#ifdef __cplusplus
}
#endif

#endif // NFC_HAL_CORE_H
/**
 * @}
 */

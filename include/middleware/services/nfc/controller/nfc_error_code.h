/**
 * Copyright (c) @CompanyNameMagicTag 2021. All rights reserved. \n
 * Description: nfc error code \n
 * Author: @CompanyNameTag \n
 * Date: 2021-08-20 \n
 */
/** @defgroup middleware_service_nfc_controller_errcode NFC Controller Error Code
 * @ingroup middleware_service_nfc_controller
 * @{
 */
#ifndef NFC_ERR_CODE_H
#define NFC_ERR_CODE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @if Eng
 * @brief  Nfc module error code type definition.
 * @else
 * @brief  NFC模块的错误码类型定义。
 * @endif
 */
typedef uint32_t NfcErrorCode;

/**
 * @if Eng
 * @brief  Nfc module return error code value.
 * @else
 * @brief  NFC模块返回的错误码值。
 * @endif
 */
enum {
    /** @if Eng NFC success.
     *  @else   NFC执行成功。 @endif */
    NFC_OK = 0,

    /** @if Eng NFC controller error code valid range is [0x80005800, 0x80005F00), 0x80005800 is first valid code.
     *  @else   NFC控制器错误码有效范围是[0x80005800, 0x80005F00)，0x80005800是第一个有效码值。 @endif */
    NFC_ERR_CODE_BEGIN = 0x80005800,

    /* NFC common error code. */
    /** @if Eng NFC open failure.
     *  @else   NFC设备打开失败。 @endif */
    NFC_ERR_CODE_OPEN_FAIL = NFC_ERR_CODE_BEGIN,
    /** @if Eng NFC close failure.
     *  @else   NFC设备关闭失败。 @endif */
    NFC_ERR_CODE_CLOSE_FAIL,
    /** @if Eng NFC write operation failure.
     *  @else   NFC设备写操作失败。 @endif */
    NFC_ERR_CODE_WRITE_FAIL,
    /** @if Eng NFC fails to receive response header, probabaly due to I2C error.
     *  @else   NFC接收回复的NCI头失败，很可能是I2C错误。 @endif */
    NFC_ERR_CODE_RECV_RSP_HEAD_I2C_ERROR,
    /** @if Eng Memory copy failure.
     *  @else   内存拷贝失败。 @endif */
    NFC_ERR_CODE_MEMCPY_FAIL,
    /** @if Eng There is a null pointer among input parameters.
     *  @else   输入参数中有空指针。 @endif */
    NFC_ERR_CODE_NULL_POINTER,
    /** @if Eng There is an invalid input parameter.
     *  @else   输入参数中有非法参数。 @endif */
    NFC_ERR_CODE_INVALID_PARAMETER,

    /* NCI core reset error code. */
    /** @if Eng NFC fails to receive NCI core reset response header, probabaly due to I2C error.
     *  @else   NFC接收NCI复位回复消息的NCI头失败，很可能是I2C错误。 @endif */
    NFC_ERR_CODE_RST_RSP_HEAD_I2C_ERR = NFC_ERR_CODE_BEGIN + 0x20,
    /** @if Eng NFC fails to receive NCI core reset notification header, probabaly due to I2C error.
     *  @else   NFC接收NCI复位通知消息的NCI头失败，很可能是I2C错误。 @endif */
    NFC_ERR_CODE_RST_NTF_HEAD_I2C_ERR,
    /** @if Eng The status field value is a failure in the received NCI core reset response.
     *  @else   NFC接收到的NCI复位回复消息里的状态信息为失败。 @endif */
    NFC_ERR_CODE_RST_RSP_STATUS_ERR,
    /** @if Eng NFC fails to write NCI core reset command, probabaly due to I2C error.
     *  @else   NFC往下写复位命令失败，很可能是I2C错误。 @endif */
    NFC_ERR_CODE_RST_NCI_WRITE_I2C_ERR,

    /* NCI core init/config related error code. */
    /** @if Eng NFC fails to receive NCI core init response.
     *  @else   NFC接收NCI初始化回复消息失败。 @endif */
    NFC_ERR_CODE_INIT_RECV_RSP_ERR = NFC_ERR_CODE_BEGIN + 0x40,
    /** @if Eng The status field value is a failure in the received NCI core init response.
     *  @else   NFC接收到的NCI初始化回复消息里的状态信息为失败。 @endif */
    NFC_ERR_CODE_INIT_RSP_STATUS_ERR,
    /** @if Eng NFC fails to receive NCI core config response.
     *  @else   NFC接收NCI核心配置回复消息失败。 @endif */
    NFC_ERR_CODE_CFG_RECV_RSP_ERR,
    /** @if Eng The status field value is a failure in the received NCI core config response.
     *  @else   NFC接收到的NCI核心配置回复消息里的状态信息为失败。 @endif */
    NFC_ERR_CODE_CFG_RSP_STATUS_ERR,
    /** @if Eng NFC fails to receive NCI discovery map response.
     *  @else   NFC接收NCI轮询映射回复消息失败。 @endif */
    NFC_ERR_CODE_DISCOV_MAP_RECV_RSP_ERR,
    /** @if Eng The status field value is a failure in the received NCI discovery map response.
     *  @else   NFC接收到的NCI轮询映射回复消息里的状态信息为失败。 @endif */
    NFC_ERR_CODE_DISCOV_MAP_RSP_STATUS_ERR,

    /* NCI core trigger discovery and detect ntf related error code. */
    /** @if Eng The NFC state is invalid for discovery command. It's in either discovery state or active state.
     *  @else   NFC收到轮询命令时候，状态不对，可能已经是轮询状态，或者是激活状态。 @endif */
    NFC_ERR_CODE_DISCOV_STATE_INVALID = NFC_ERR_CODE_BEGIN + 0x60,
    /** @if Eng The discovery parameters is too long to fit in internal buffer, probabaly due to wrong input parameters.
     *  @else   NFC收到轮询命令参数太长超过了内部buff空间，很可能输入参数有误。 @endif */
    NFC_ERR_CODE_DISCOV_PARAM_BUFF_OVERFLOW,
    /** @if Eng NFC fails to receive NCI discovery response.
     *  @else   NFC接收NCI轮询回复消息失败。 @endif */
    NFC_ERR_CODE_DISCOV_RECV_RSP_ERR,
    /** @if Eng The status field value is a failure in the received NCI discovery response.
     *  @else   NFC接收到的NCI轮询回复消息里的状态信息为失败。 @endif */
    NFC_ERR_CODE_DISCOV_RSP_STATUS_ERR,
    /** @if Eng NFC fails to receive NCI technology detect notification.
     *  @else   NFC接收NCI技术发现通知消息失败。 @endif */
    NFC_ERR_CODE_DETECT_NTF_I2C_RECV,
    /** @if Eng The technoloy detect notification indicates no card found.
     *  @else   NFC技术发现通知的内容显示没有发现卡。 @endif */
    NFC_ERR_CODE_DETECT_NO_FOUND,

    /* NCI core rf_intf_activation_NTF & discovery_NTF related error code. */
    /** @if Eng NFC fails to receive NCI interface activation notification.
     *  @else   NFC接收NCI接口激活通知消息失败。 @endif */
    NFC_ERR_CODE_ACT_NTF_HEAD_I2C_ERR = NFC_ERR_CODE_BEGIN + 0x80,
    /** @if Eng NFC receive wrong NCI packet instead of discovery notification or interface activation notification.
     *  @else   NFC接收到错误消息，而非轮询通知或接口激活通知消息。 @endif */
    NFC_ERR_CODE_ACT_NTF_RECV_WRONG_PKT,
    /** @if Eng There are invalid parameters when processing interface activation notification.
     *  @else   处理接口激活通知消息时发现有非法参数。 @endif */
    NFC_ERR_CODE_ACT_NTF_INVALID_PARAM_ERR,
    /** @if Eng NFC fails to receive NCI discovery notification header.
     *  @else   NFC接收NCI轮询发现通知消息的NCI头失败。 @endif */
    NFC_ERR_CODE_DISCOV_NTF_HEAD_I2C_ERR,
    /** @if Eng The payload part is not right in received NCI discovery notification.
     *  @else   NFC接收到NCI轮询发现通知消息的载荷部分信息不对。 @endif */
    NFC_ERR_CODE_DISCOV_NTF_PLD_ERR,
    /** @if Eng No proper protocol is found according to input priority when there're multiple protocols to select.
     *  @else   根据输入的选择优先级，无法从多个轮询发现的协议中找到合适的协议去激活。 @endif */
    NFC_ERR_CODE_DISCOV_NTF_NO_PROP_PROTOCOL_ERR,

    /* NCI core select & deactivate related error code. */
    /** @if Eng NFC fails to receive NCI select response.
     *  @else   NFC接收NCI选择激活回复消息失败。 @endif */
    NFC_ERR_CODE_SELECT_RSP_I2C_ERR = NFC_ERR_CODE_BEGIN + 0xA0,
    /** @if Eng The status field value is a failure in the received NCI select response.
     *  @else   NFC接收到的NCI选择激活回复消息里的状态信息为失败。 @endif */
    NFC_ERR_CODE_SELECT_RSP_STATUS_ERR,
    /** @if Eng NFC fails to receive NCI interface activation notification after select response.
     *  @else   NFC接收完选择激活回复后，再接收NCI激活通知消息失败。 @endif */
    NFC_ERR_CODE_SELECT_NTF_HEAD_I2C_ERR,
    /** @if Eng NFC fails to receive NCI deactivation response.
     *  @else   NFC接收NCI去激活回复消息失败。 @endif */
    NFC_ERR_CODE_DEACT_RECV_RSP_ERR,
    /** @if Eng The status field value is a failure in the received NCI deactivation response.
     *  @else   NFC接收到的NCI去激活回复消息里的状态信息为失败。 @endif */
    NFC_ERR_CODE_DEACT_RSP_STATUS_ERR,
    /** @if Eng NFC fails to receive NCI deactivation notification.
     *  @else   NFC接收NCI去激活通知消息失败。 @endif */
    NFC_ERR_CODE_DEACT_NTF_HEAD_I2C_ERR,

    /* NFC low power error code. */
    /** @if Eng NFC fails to receive NCI idle sleep response.
     *  @else   NFC接收NCI空闲睡眠的回复消息失败。 @endif */
    NFC_ERR_CODE_ENTER_IDLE_SLP_RECV_RSP_ERR = NFC_ERR_CODE_BEGIN + 0xC0,
    /** @if Eng The status field value is a failure in the received NCI idle sleep response.
     *  @else   NFC接收到的NCI空闲睡眠的回复消息里的状态信息为失败。 @endif */
    NFC_ERR_CODE_ENTER_IDLE_SLP_RSP_STATUS_ERR,
    /** @if Eng NFC fails to receive NCI low power config response.
     *  @else   NFC接收NCI低功耗使能配置的回复消息失败。 @endif */
    NFC_ERR_CODE_CFG_LOW_POWER_RECV_ERR,
    /** @if Eng The status field value is a failure in the received NCI low power config response.
     *  @else   NFC接收到的NCI低功耗使能配置的回复消息里的状态信息为失败。 @endif */
    NFC_ERR_CODE_CFG_LOW_POWER_STATUS_ERR,

    /* NFC receive & send data error code. */
    /** @if Eng NFC fails to receive any NCI packet.
     *  @else   NFC接收任意NCI包失败。 @endif */
    NFC_ERR_CODE_PKT_RECV_I2C_ERR = NFC_ERR_CODE_BEGIN + 0xE0,
    /** @if Eng NFC fails to receive data flow control packet.
     *  @else   NFC接收数据流控包失败。 @endif */
    NFC_ERR_CODE_DATA_FLOW_RECV_ERR,
    /** @if Eng NFC fails to receive data packet.
     *  @else   NFC接收数据包失败。 @endif */
    NFC_ERR_CODE_DATA_RECV_ERR,
    /** @if Eng NFC fails to send data packet.
     *  @else   NFC发送数据包失败。 @endif */
    NFC_ERR_CODE_DATA_SND_ERR,

    /* NFC continuous Tx/Rx error code. */
    /** @if Eng NFC fails to receive NCI response of continuous RX enable command.
     *  @else   NFC接收NCI常收使能的回复消息失败。 @endif */
    NFC_ERR_CODE_CONT_RX_EN_RECV_RSP_ERR = NFC_ERR_CODE_BEGIN + 0x100,
    /** @if Eng The status field value is a failure in the received NCI continuous RX enable response.
     *  @else   NFC接收到的NCI常收使能的回复消息里的状态信息为失败。 @endif */
    NFC_ERR_CODE_CONT_RX_EN_RSP_STATUS_ERR,
    /** @if Eng NFC fails to receive NCI response of continuous RX run command.
     *  @else   NFC接收NCI常收启动的回复消息失败。 @endif */
    NFC_ERR_CODE_CONT_RX_RUN_RECV_RSP_ERR,
    /** @if Eng The status field value is a failure in the received NCI continuous RX run response.
     *  @else   NFC接收到的NCI常收启动的回复消息里的状态信息为失败。 @endif */
    NFC_ERR_CODE_CONT_RX_RUN_RSP_STATUS_ERR,
    /** @if Eng NFC fails to receive NCI response of continuous RX stop command.
     *  @else   NFC接收NCI常收停止的回复消息失败。 @endif */
    NFC_ERR_CODE_CONT_RX_STOP_RECV_RSP_ERR,
    /** @if Eng The status field value is a failure in the received NCI continuous RX stop response.
     *  @else   NFC接收到的NCI常收停止的回复消息里的状态信息为失败。 @endif */
    NFC_ERR_CODE_CONT_RX_STOP_RSP_STATUS_ERR,
    /** @if Eng NFC fails to receive NCI response of continuous RX disable command.
     *  @else   NFC接收NCI常收禁能的回复消息失败。 @endif */
    NFC_ERR_CODE_CONT_RX_DISABLE_RECV_RSP_ERR,
    /** @if Eng The status field value is a failure in the received NCI continuous RX disable response.
     *  @else   NFC接收到的NCI常收禁能的回复消息里的状态信息为失败。 @endif */
    NFC_ERR_CODE_CONT_RX_DISABLE_RSP_STATUS_ERR,

    /* NFC nfcee discovery & enable error code. */
    /** @if Eng NFC fails to receive NCI NFCEE discovery response.
     *  @else   NFC接收NCI NFCEE发现的回复消息失败。 @endif */
    NFC_ERR_CODE_NFCEE_DISCOV_RECV_RSP_ERR = NFC_ERR_CODE_BEGIN + 0x120,
    /** @if Eng The status field value is a failure in the received NCI NFCEE discovery response.
     *  @else   NFC接收到的NCI NFCEE发现的回复消息里的状态信息为失败。 @endif */
    NFC_ERR_CODE_NFCEE_DISCOV_RSP_STATUS_ERR,
    /** @if Eng No NFCEE is found during NFCEE discovery process.
     *  @else   NFC NFCEE发现流程中没有找到NFCEE。 @endif */
    NFC_ERR_CODE_NFCEE_DISCOV_NOT_FOUND_ERR,
    /** @if Eng NFC fails to receive NCI NFCEE enable response.
     *  @else   NFC接收NCI NFCEE使能的回复消息失败。 @endif */
    NFC_ERR_CODE_NFCEE_ENABLE_RECV_RSP_ERR,
    /** @if Eng The status field value is a failure in the received NCI NFCEE enable response.
     *  @else   NFC接收到的NCI NFCEE使能的回复消息里的状态信息为失败。 @endif */
    NFC_ERR_CODE_NFCEE_ENABLE_RSP_STATUS_ERR,
    /** @if Eng NFC fails to activate NFCEE during NCI NFCEE enable process.
     *  @else   NFC在使能NFCEE的流程中NFCEE激活失败。 @endif */
    NFC_ERR_CODE_NFCEE_ENABLE_ACT_FAIL,
    /** @if Eng No RF discovery request is found during NFCEE enable process.
     *  @else   NFC NFCEE使能流程中没有找到射频发现请求。 @endif */
    NFC_ERR_CODE_NFCEE_ENABLE_RF_DISCOV_REQ_NOT_FOUND_ERR,

    /* NFC set listen route table & HCI RAM info restore/store. */
    /** @if Eng NFC fails to receive NCI response of setting listen route table command.
     *  @else   NFC接收NCI设置侦听路由表命令的回复消息失败。 @endif */
    NFC_ERR_CODE_SET_LISTEN_ROUTE_RECV_RSP_ERR = NFC_ERR_CODE_BEGIN + 0x140,
    /** @if Eng The status field value is a failure in the received NCI response of setting listen route table.
     *  @else   NFC接收到的NCI设置侦听路由表的回复消息里的状态信息为失败。 @endif */
    NFC_ERR_CODE_SET_LISTEN_ROUTE_RSP_STATUS_ERR,
    /** @if Eng NFC fails to receive NCI response of restoring HCI RAM information command.
     *  @else   NFC接收NCI恢复HCI内存信息命令的回复消息失败。 @endif */
    NFC_ERR_CODE_PROP_HCI_RAM_RESTORE_RECV_RSP_ERR,
    /** @if Eng The status field value is a failure in the received NCI response of restoring HCI RAM information.
     *  @else   NFC接收到的NCI恢复HCI内存信息的回复消息里的状态信息为失败。 @endif */
    NFC_ERR_CODE_PROP_HCI_RAM_RESTORE_RSP_STATUS_ERR,
    /** @if Eng NFC fails to receive NCI response of storing HCI RAM information command.
     *  @else   NFC接收NCI保存HCI内存信息命令的回复消息失败。 @endif */
    NFC_ERR_CODE_PROP_HCI_RAM_STORE_RECV_RSP_ERR,
    /** @if Eng The status field value is a failure in the received NCI response of storing HCI RAM information.
     *  @else   NFC接收到的NCI保存HCI内存信息的回复消息里的状态信息为失败。 @endif */
    NFC_ERR_CODE_PROP_HCI_RAM_STORE_RSP_STATUS_ERR,

    /* NFC T1T tag operation error code. */
    /** @if Eng The function input parameters are invalid for T1T tag operation module.
     *  @else   T1T卡片操作模块的函数入参非法。 @endif */
    NFC_ERR_CODE_T1T_INPUT_PARAM_INVALID_ERR = NFC_ERR_CODE_BEGIN + 0x200,
    /** @if Eng NFC fails to execute T1T read ID command.
     *  @else   T1T卡片的读ID操作命令执行失败。 @endif */
    NFC_ERR_CODE_T1T_PROC_RID_ERR,
    /** @if Eng NFC fails to execute T1T read all command.
     *  @else   T1T卡片的读所有静态内容的操作命令执行失败。 @endif */
    NFC_ERR_CODE_T1T_PROC_RALL_ERR,
    /** @if Eng NFC fails to execute T1T read byte command.
     *  @else   T1T卡片的单字节读操作命令执行失败。 @endif */
    NFC_ERR_CODE_T1T_PROC_READ_ERR,
    /** @if Eng NFC fails to execute T1T write byte with erasion command.
     *  @else   T1T卡片的带擦除的单字节写操作命令执行失败。 @endif */
    NFC_ERR_CODE_T1T_PROC_WRITE_E_ERR,
    /** @if Eng NFC fails to execute T1T write byte without erasion command.
     *  @else   T1T卡片的不带擦除的单字节写操作命令执行失败。 @endif */
    NFC_ERR_CODE_T1T_PROC_WRITE_NE_ERR,
    /** @if Eng NFC fails to execute T1T read segment command.
     *  @else   T1T卡片的读数据段操作命令执行失败。 @endif */
    NFC_ERR_CODE_T1T_PROC_RSEG_ERR,
    /** @if Eng NFC fails to execute T1T read 8 bytes command.
     *  @else   T1T卡片的读8个字节的操作命令执行失败。 @endif */
    NFC_ERR_CODE_T1T_PROC_READ8_ERR,
    /** @if Eng NFC fails to execute T1T write 8 bytes with erasion command.
     *  @else   T1T卡片的带擦除的写8个字节的操作命令执行失败。 @endif */
    NFC_ERR_CODE_T1T_PROC_WRITE_E8_ERR,
    /** @if Eng NFC fails to execute T1T write 8 bytes without erasion command.
     *  @else   T1T卡片的不带擦除的写8个字节的操作命令执行失败。 @endif */
    NFC_ERR_CODE_T1T_PROC_WRITE_NE8_ERR,

    /* NFC T2T tag operation error code. */
    /** @if Eng The function input parameters are invalid for T2T tag operation module.
     *  @else   T2T卡片操作模块的函数入参非法。 @endif */
    NFC_ERR_CODE_T2T_INPUT_PARAM_INVALID = NFC_ERR_CODE_BEGIN + 0x220,
    /** @if Eng NFC fails to execute T2T read command.
     *  @else   T2T卡片的读操作命令执行失败。 @endif */
    NFC_ERR_CODE_T2T_PROC_READ_ERR,
    /** @if Eng NFC fails to execute T2T write command.
     *  @else   T2T卡片的写操作命令执行失败。 @endif */
    NFC_ERR_CODE_T2T_PROC_WRITE_ERR,
    /** @if Eng NFC fails to send or get response of T2T sector select packet 1.
     *  @else   在T2T卡片的扇区选择操作时，发送第一个包失败或接收其回复失败。 @endif */
    NFC_ERR_CODE_T2T_PROC_SECTOR_SELECT_PACKET_1_ERR,
    /** @if Eng NFC fails to send T2T sector select packet 2.
     *  @else   在T2T卡片的扇区选择操作时，发送第二个包失败。 @endif */
    NFC_ERR_CODE_T2T_PROC_SECTOR_SELECT_PACKET_2_SEND_ERR,
    /** @if Eng NFC fails to receive flow control packet after sending T2T sector select packet 2.
     *  @else   在T2T卡片的扇区选择操作时，发送第二个包后，没有收到对应的流控数据帧。 @endif */
    NFC_ERR_CODE_T2T_PROC_SECTOR_SELECT_PACKET_2_RCV_FLOW_CTRL_ERR,
    /** @if Eng NFC receive wrong response of T2T sector select packet 2, where timeout is expected.
     *  @else   在T2T卡片的扇区选择操作时，发送第二个包后，期望超时内无响应，但却收到了异常数据。 @endif */
    NFC_ERR_CODE_T2T_PROC_SECTOR_SELECT_PACKET_2_WAIT_TIMEOUT_ERR,

    /* NFC T3T tag operation error code. */
    /** @if Eng The function input parameters are invalid for T3T tag operation module.
     *  @else   T3T卡片操作模块的函数入参非法。 @endif */
    NFC_ERR_CODE_T3T_INPUT_PARAM_INVALID = NFC_ERR_CODE_BEGIN + 0x240,
    /** @if Eng NFC fails to receive T3T polling response.
     *  @else   T3T卡片的轮询检测请求的回复消息接收失败。 @endif */
    NFC_ERR_CODE_T3T_POLLING_RECV_RSP_ERR,
    /** @if Eng The status field value is a failure in the received T3T polling response.
     *  @else   接收到的T3T卡片轮询检测请求的回复消息里的状态信息为失败。 @endif */
    NFC_ERR_CODE_T3T_POLLING_RSP_STATUS_ERR,
    /** @if Eng NFC fails to receive T3T polling notification.
     *  @else   T3T卡片的轮询检测请求的通知消息接收失败。 @endif */
    NFC_ERR_CODE_T3T_POLLING_NTF_RECV_ERR,
    /** @if Eng The status field value is a failure in the received T3T polling notification.
     *  @else   接收到的T3T卡片轮询检测请求的通知消息里的状态信息为失败。 @endif */
    NFC_ERR_CODE_T3T_POLLING_NTF_STATUS_ERR,
    /** @if Eng NFC fails to decode T3T polling notification.
     *  @else   T3T卡片的轮询检测请求的通知消息解析失败。 @endif */
    NFC_ERR_CODE_T3T_POLLING_NTF_DECODE_ERR,
    /** @if Eng NFC fails to get response of T3T update command.
     *  @else   T3T卡片的更新命令的回复消息接收失败。 @endif */
    NFC_ERR_CODE_T3T_UPDATE_CMD_RSP_ERR,
    /** @if Eng T3T update response status flag1 is an error.
     *  @else   T3T卡片的更新回复的状态标志1为失败。 @endif */
    NFC_ERR_CODE_T3T_UPDATE_RSP_DECODE_FLAG1_ERR,
    /** @if Eng NFC fails to get response of T3T check command.
     *  @else   T3T卡片的检查命令的回复消息接收失败。 @endif */
    NFC_ERR_CODE_T3T_CHECK_CMD_RSP_ERR,
    /** @if Eng T3T check response length is invalid.
     *  @else   T3T卡片的检查回复的长度信息不对。 @endif */
    NFC_ERR_CODE_T3T_CHECK_RSP_DECODE_LEN_ERR,
    /** @if Eng T3T check response status flag1 is an error.
     *  @else   T3T卡片的检查回复的状态标志1为失败。 @endif */
    NFC_ERR_CODE_T3T_CHECK_RSP_DECODE_FLAG1_ERR,
    /** @if Eng The number of blocks in T3T check response is not matched to request.
     *  @else   T3T卡片的检查回复消息里的数据块数目和请求的不相符。 @endif */
    NFC_ERR_CODE_T3T_CHECK_RSP_DECODE_BLK_NUM_ERR,
    /** @if Eng The activated card is found lost by T3T polling command.
     *  @else   通过T3T轮询检测命令，发现已激活卡片丢失。 @endif */
    NFC_ERR_CODE_T3T_DETECT_TARGET_CARD_LOST,
    /** @if Eng T3T check sum in attribute information is an error.
     *  @else   T3T卡片的校验和检查失败。 @endif */
    NFC_ERR_CODE_T3T_CHECK_ATTRIBUTE_CHECK_SUM_ERR,

    /* NFC T4T tag operation error code. */
    /** @if Eng The function input parameters are invalid for T4T tag operation module.
     *  @else   T4T卡片操作模块的函数入参非法。 @endif */
    NFC_ERR_CODE_T4T_INPUT_PARAM_INVALID = NFC_ERR_CODE_BEGIN + 0x260,
    /** @if Eng NFC fails to finish T4T select AID operation.
     *  @else   T4T卡片的选择AID操作失败。 @endif */
    NFC_ERR_CODE_T4T_SELECT_AID_ERR,
    /** @if Eng NFC fails to finish T4T select FID operation.
     *  @else   T4T卡片的选择FID操作失败。 @endif */
    NFC_ERR_CODE_T4T_SELECT_FID_ERR,
    /** @if Eng NFC fails to finish read data operation.
     *  @else   T4T卡片的读数据操作失败。 @endif */
    NFC_ERR_CODE_T4T_READ_DATA_ERR,
    /** @if Eng NFC fails to finish write data operation.
     *  @else   T4T卡片的写数据操作失败。 @endif */
    NFC_ERR_CODE_T4T_WRITE_DATA_ERR,
    /** @if Eng NFC fails to receive T4T NAK presence check response.
     *  @else   T4T卡片的在位检测回复消息接收失败。 @endif */
    NFC_ERR_CODE_T4T_NAK_PRES_CHK_RECV_RSP_ERR,
    /** @if Eng The status field value is a failure in the received NCI response of T4T NAK presence check.
     *  @else   NFC接收到的T4T在位检测的NCI回复消息里的状态信息为失败。 @endif */
    NFC_ERR_CODE_T4T_NAK_PRES_CHK_RECV_RSP_STATUS_ERR,
    /** @if Eng NFC fails to receive T4T NAK presence check notification.
     *  @else   T4T卡片的在位检测回复通知接收失败。 @endif */
    NFC_ERR_CODE_T4T_NAK_PRES_CHK_RECV_NTF_ERR,

    /* NFC T5T tag operation error code. */
    /** @if Eng The function input parameters are invalid for T5T tag operation module.
     *  @else   T5T卡片操作模块的函数入参非法。 @endif */
    NFC_ERR_CODE_T5T_INPUT_PARAM_INVALID_ERR = NFC_ERR_CODE_BEGIN + 0x280,
    /** @if Eng NFC fails to finish T5T read single block operation.
     *  @else   T5T卡片的读单个数据块的操作失败。 @endif */
    NFC_ERR_CODE_T5T_PROC_READ_SINGLE_ERR,
    /** @if Eng NFC fails to finish T5T write single block operation.
     *  @else   T5T卡片的写单个数据块的操作失败。 @endif */
    NFC_ERR_CODE_T5T_PROC_WRITE_SINGLE_ERR,
    /** @if Eng NFC fails to finish T5T lock single block operation.
     *  @else   T5T卡片的锁定单个数据块的操作失败。 @endif */
    NFC_ERR_CODE_T5T_PROC_LOCK_SINGLE_ERR,
    /** @if Eng NFC fails to finish T5T read multiple blocks operation.
     *  @else   T5T卡片的读多个数据块的操作失败。 @endif */
    NFC_ERR_CODE_T5T_PROC_READ_MULT_ERR,
    /** @if Eng NFC fails to finish T5T extended read single block operation.
     *  @else   T5T卡片的扩展读单个数据块的操作失败。 @endif */
    NFC_ERR_CODE_T5T_PROC_EX_READ_SINGLE_ERR,
    /** @if Eng NFC fails to finish T5T extended write single block operation.
     *  @else   T5T卡片的扩展写单个数据块的操作失败。 @endif */
    NFC_ERR_CODE_T5T_PROC_EX_WRITE_SINGLE_ERR,
    /** @if Eng NFC fails to finish T5T extended lock single block operation.
     *  @else   T5T卡片的扩展锁定单个数据块的操作失败。 @endif */
    NFC_ERR_CODE_T5T_PROC_EX_LOCK_SINGLE_ERR,
    /** @if Eng NFC fails to finish T5T extended read multiple blocks operation.
     *  @else   T5T卡片的扩展读多个数据块的操作失败。 @endif */
    NFC_ERR_CODE_T5T_PROC_EX_READ_MULT_ERR,
    /** @if Eng NFC fails to finish T5T select operation.
     *  @else   T5T卡片的选择操作失败。 @endif */
    NFC_ERR_CODE_T5T_PROC_SELECT_ERR,
    /** @if Eng NFC fails to finish T5T sleep operation.
     *  @else   T5T卡片的睡眠操作失败。 @endif */
    NFC_ERR_CODE_T5T_PROC_SLPV_ERR,

    /* NFC NDEF process error code. */
    /** @if Eng The function input parameters are invalid for NDEF module.
     *  @else   NDEF处理模块的函数入参非法。 @endif */
    NFC_ERR_CODE_NDEF_PROC_INPUT_PARAM_INVALID = NFC_ERR_CODE_BEGIN + 0x300,
    /** @if Eng NDEF reset process meets with wrong protocol.
     *  @else   NDEF复位处理发现不支持的非法协议。 @endif */
    NFC_ERR_CODE_NDEF_PROC_RESET_WRONG_PROTOCOL,
    /** @if Eng NFC fails to finish read CC operation during NDEF procedure.
     *  @else   NDEF处理流程中的读CC操作失败。 @endif */
    NFC_ERR_CODE_NDEF_PROC_TAG_READ_CC,
    /** @if Eng NFC fails to finish search NDEF operation.
     *  @else   搜索NDEF操作失败。 @endif */
    NFC_ERR_CODE_NDEF_PROC_TAG_SEARCH_NDEF,
    /** @if Eng NFC fails to finish read NDEF length operation.
     *  @else   读NDEF长度操作失败。 @endif */
    NFC_ERR_CODE_NDEF_PROC_TAG_READ_NDEF_LEN,
    /** @if Eng NFC fails to finish read NDEF data operation.
     *  @else   读NDEF数据操作失败。 @endif */
    NFC_ERR_CODE_NDEF_PROC_TAG_READ_NDEF_MESSAGE,
    /** @if Eng NFC fails to finish reset NDEF length operation.
     *  @else   复位NDEF长度操作失败。 @endif */
    NFC_ERR_CODE_NDEF_PROC_TAG_RESET_NDEF_LEN,
    /** @if Eng NFC fails to finish write NDEF data operation.
     *  @else   写NDEF数据操作失败。 @endif */
    NFC_ERR_CODE_NDEF_PROC_TAG_WRITE_NDEF_MESSAGE,
    /** @if Eng NFC fails to finish update NDEF length operation.
     *  @else   更新NDEF长度操作失败。 @endif */
    NFC_ERR_CODE_NDEF_PROC_TAG_UPDATE_NDEF_LEN,
    /** @if Eng NFC detects wrong tag during NDEF procedure.
     *  @else   在NDEF处理流程中发现不支持的非法卡片。 @endif */
    NFC_ERR_CODE_NDEF_PROC_DETECT_WRONG_TAG,
    /** @if Eng NFC detects no NDEF TLV on the tag.
     *  @else   在卡片上没有发现NDEF TLV。 @endif */
    NFC_ERR_CODE_NDEF_PROC_DETECT_TLV_NOT_FOUND,
    /** @if Eng The length of NDEF content on the tag is 0.
     *  @else   在卡片上的NDEF内容长度是0。 @endif */
    NFC_ERR_CODE_NDEF_PROC_READ_EMPTY_NDEF,
    /** @if Eng The input buffer length is too short to fill all of the NDEF data.
     *  @else   输入的缓存空间太小无法装填所有的NDEF数据。 @endif */
    NFC_ERR_CODE_NDEF_PROC_READ_BUFF_SHORTAGE,
    /** @if Eng The NDEF information on the tag is for read only, not for writing.
     *  @else   卡片上的NDEF信息是只读，无法改写。 @endif */
    NFC_ERR_CODE_NDEF_PROC_WRITE_TLV_READ_ONLY,
    /** @if Eng The NDEF length to write overflows the total memory space on the tag.
     *  @else   要写入的NDEF长度超过了卡片上的NDEF总存储空间。 @endif */
    NFC_ERR_CODE_NDEF_PROC_WRITE_LEN_OVERFLOW,
    /** @if Eng The NDEF data is in writing process when read it.
     *  @else   读NDEF内容时，NDEF内容正在被写入过程中。 @endif */
    NFC_ERR_CODE_NDEF_PROC_READ_WHILE_WRITE_ON,

    /** @if Eng NFC controller error code end, valid NFC controller error code should be added above this line.
     *  @else   NFC控制器错误码结尾，有效的NFC控制器错误码应该在本枚举值之前定义。 @endif */
    NFC_ERR_CODE_END = 0x80005F00
};

#ifdef __cplusplus
}
#endif

#endif // NFC_ERR_CODE_H
/**
 * @}
 */

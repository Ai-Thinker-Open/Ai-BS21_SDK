/**
 * Copyright (c) @CompanyNameMagicTag 2021. All rights reserved. \n
 * Description: nfc defines \n
 * Author: @CompanyNameTag \n
 * Date: 2021-08-20 \n
 */
/** @defgroup middleware_service_nfc_controller_defines NFC Controller Defines
 * @ingroup middleware_service_nfc_controller
 * @{
 */
#ifndef NFC_DEFS_H
#define NFC_DEFS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @if Eng
 * @brief  NCI maximum payload byte length.
 * @else
 * @brief  NFC NCI协议标准中最大载荷字节长度。
 * @endif
 */
#define NCI_MAX_PAYLOAD_LEN       255

/**
 * @if Eng
 * @brief  NFC HAL maximum buffer length.
 * @else
 * @brief  NFC硬件抽象层单帧最大缓冲区字节长度。
 * @endif
 */
#define HAL_MAX_BUF_LEN           258

/**
 * @if Eng
 * @brief  NFC HAL short buffer length.
 * @else
 * @brief  NFC硬件抽象层用于单帧交互内容长度较短的场景下缓冲区字节长度。
 * @endif
 */
#define HAL_SHORT_BUFF_LEN        32

/**
 * @if Eng
 * @brief  NFC NCI header length.
 * @else
 * @brief  NFC NCI协议标准中NCI包头的字节长度。
 * @endif
 */
#define NCI_HEAD_LEN              3

/**
 * @if Eng
 * @brief  NFC NCI length position in NCI header.
 * @else
 * @brief  NFC NCI协议标准中NCI载荷长度域在NCI包头的位置。
 * @endif
 */
#define NCI_LEN_POS               2

/**
 * @if Eng
 * @brief  NFC default read timeout for NCI control packet in millisecond.
 * @else
 * @brief  NFC默认的读控制帧的超时时间（毫秒）。
 * @endif
 */
#define NCI_READ_TO               1000

/**
 * @if Eng
 * @brief  NFC default read timeout for NCI data packet in millisecond.
 * @else
 * @brief  NFC默认的读数据帧的超时时间（毫秒）。
 * @endif
 */
#define NCI_READ_DATA_TO          1500

/**
 * @if Eng
 * @brief  NFC NCI RF frame corrupted indication.
 * @else
 * @brief  NFC NCI协议标准中指示空口射频帧信息被损毁的状态值。
 * @endif
 */
#define NCI_RF_FRAME_CORRUPTED    0x02

/**
 * @if Eng
 * @brief  A technology sense response length.
 * @else
 * @brief  A技术探查帧的回复帧的长度。
 * @endif
 */
#define SENS_RES_LEN              2

/**
 * @if Eng
 * @brief  B technology sense response maximum length.
 * @else
 * @brief  B技术探查帧的回复帧的最大长度。
 * @endif
 */
#define SENSB_RES_MAX_LEN         12

/**
 * @if Eng
 * @brief  F technology sense response maximum length.
 * @else
 * @brief  F技术探查帧的回复帧的最大长度。
 * @endif
 */
#define SENSF_RES_MAX_LEN         18

/**
 * @if Eng
 * @brief  A technology NFCID1 maximum length.
 * @else
 * @brief  A技术的NFCID1的最大长度。
 * @endif
 */
#define NFCID1_MAX_LEN            10

/**
 * @if Eng
 * @brief  A technology NFCID1 length for cascade level-1.
 * @else
 * @brief  A技术的NFCID1满足级联级别1的长度。
 * @endif
 */
#define NFCID1_CASLVL1_LEN        4

/**
 * @if Eng
 * @brief  A technology NFCID1 length for cascade level-2.
 * @else
 * @brief  A技术的NFCID1满足级联级别2的长度。
 * @endif
 */
#define NFCID1_CASLVL2_LEN        7

/**
 * @if Eng
 * @brief  A technology NFCID1 length for cascade level-3.
 * @else
 * @brief  A技术的NFCID1满足级联级别3的长度。
 * @endif
 */
#define NFCID1_CASLVL3_LEN        10

/**
 * @if Eng
 * @brief  B technology NFCID0 length.
 * @else
 * @brief  B技术NFCID0的长度。
 * @endif
 */
#define NFCID0_LEN                4

/**
 * @if Eng
 * @brief  F technology NFCID2 length.
 * @else
 * @brief  F技术的NFCID2的长度。
 * @endif
 */
#define NFCID2_LEN                8

/**
 * @if Eng
 * @brief  V technology UID length.
 * @else
 * @brief  V技术的UID的长度。
 * @endif
 */
#define UID_LEN                   8

/**
 * @if Eng
 * @brief  T3T PAD0 field length.
 * @else
 * @brief  T3T帧中PAD0域的长度。
 * @endif
 */
#define T3T_PAD0_LEN                 2

/**
 * @if Eng
 * @brief  T3T PAD1 field length.
 * @else
 * @brief  T3T帧中PAD1域的长度。
 * @endif
 */
#define T3T_PAD1_LEN                 3

/**
 * @if Eng
 * @brief  T3T RD field length.
 * @else
 * @brief  T3T帧中RD域的长度。
 * @endif
 */
#define T3T_RD_LEN                   2

/**
 * @if Eng
 * @brief  T3T polling notification responses maximum number in one NCI packet.
 * @else
 * @brief  单个NCI包中的T3T轮询回复通知的最大个数。
 * @endif
 */
#define T3T_POLL_SENSF_RES_MAX_SIZE  13

/**
 * @if Eng
 * @brief  RF technology-mode in NFC NCI specification.
 * @else
 * @brief  NFC NCI协议标准中的射频技术模式。
 * @endif
 */
enum NFC_NCI_RF_TECH_MODE_ENUM {
    /** @if Eng  Technology A passive poll mode.
     *  @else    技术A的被动轮询模式。 @endif */
    NFC_NCI_A_PASSIVE_POLL_MODE   = 0x00,
    /** @if Eng  Technology B passive poll mode.
     *  @else    技术B的被动轮询模式。 @endif */
    NFC_NCI_B_PASSIVE_POLL_MODE   = 0x01,
    /** @if Eng  Technology F passive poll mode.
     *  @else    技术F的被动轮询模式。 @endif */
    NFC_NCI_F_PASSIVE_POLL_MODE   = 0x02,
    /** @if Eng  Active poll mode.
     *  @else    主动轮询模式。 @endif */
    NFC_NCI_ACTIVE_POLL_MODE      = 0x03,
    /** @if Eng  Technology V passive poll mode.
     *  @else    技术V的被动轮询模式。 @endif */
    NFC_NCI_V_PASSIVE_POLL_MODE   = 0x06,
    /** @if Eng  Technology A passive listen mode.
     *  @else    技术A的被动侦听模式。 @endif */
    NFC_NCI_A_PASSIVE_LISTEN_MODE = 0x80,
    /** @if Eng  Technology B passive listen mode.
     *  @else    技术B的被动侦听模式。 @endif */
    NFC_NCI_B_PASSIVE_LISTEN_MODE = 0x81,
    /** @if Eng  Technology F passive listen mode.
     *  @else    技术F的被动侦听模式。 @endif */
    NFC_NCI_F_PASSIVE_LISTEN_MODE = 0x82,
    /** @if Eng  Active listen mode.
     *  @else    主动侦听模式。 @endif */
    NFC_NCI_ACTIVE_LISTEN_MODE    = 0x83,
};

/**
 * @if Eng
 * @brief  RF protocol in NFC NCI specification.
 * @else
 * @brief  NFC NCI协议标准中的射频协议。
 * @endif
 */
enum NFC_NCI_RF_PROTOCOL_ENUM {
    /** @if Eng  Undetermined RF protocol.
     *  @else    未定义的射频协议。 @endif */
    NFC_NCI_RF_PROTOCOL_UNDETERMINED = 0x00,
    /** @if Eng  RF protocol T1T.
     *  @else    T1T射频协议。 @endif */
    NFC_NCI_RF_PROTOCOL_T1T          = 0x01,
    /** @if Eng  RF protocol T2T.
     *  @else    T2T射频协议。 @endif */
    NFC_NCI_RF_PROTOCOL_T2T          = 0x02,
    /** @if Eng  RF protocol T3T.
     *  @else    T3T射频协议。 @endif */
    NFC_NCI_RF_PROTOCOL_T3T          = 0x03,
    /** @if Eng  RF protocol ISO-DEP.
     *  @else    ISO-DEP射频协议。 @endif */
    NFC_NCI_RF_PROTOCOL_ISO_DEP      = 0x04,
    /** @if Eng  RF protocol NFC-DEP.
     *  @else    NFC-DEP射频协议。 @endif */
    NFC_NCI_RF_PROTOCOL_NFC_DEP      = 0x05,
    /** @if Eng  RF protocol T5T.
     *  @else    T5T射频协议。 @endif */
    NFC_NCI_RF_PROTOCOL_T5T          = 0x06,
    /** @if Eng  Proprietary RF protocol A.
     *  @else    私有射频协议A。 @endif */
    NFC_NCI_RF_PROP_PROTOCOL_A       = 0x80,
};

/**
 * @if Eng
 * @brief  RF interface in NFC NCI specification.
 * @else
 * @brief  NFC NCI协议标准中的射频接口。
 * @endif
 */
enum NFC_NCI_RF_INTERFACE_ENUM {
    /** @if Eng  NFCEE direct RF interface.
     *  @else    NFCEE直连模式的射频接口。 @endif */
    NFC_NCI_NFCEE_DIRECT_RF_INTERFACE = 0x00,
    /** @if Eng  Frame RF interface.
     *  @else    帧透传射频接口。 @endif */
    NFC_NCI_FRAME_RF_INTERFACE        = 0x01,
    /** @if Eng  ISO-DEP protocol based RF interface.
     *  @else    基于ISO-DEP协议的射频接口。 @endif */
    NFC_NCI_ISODEP_RF_INTERFACE       = 0x02,
    /** @if Eng  NFC-DEP protocol based RF interface.
     *  @else    基于NFC-DEP协议的射频接口。 @endif */
    NFC_NCI_NFCDEP_RF_INTERFACE       = 0x03,
    /** @if Eng  Proprietary protocol A based RF interface.
     *  @else    基于私有协议A的射频接口。 @endif */
    NFC_NCI_PROP_A_RF_INTERFACE       = 0x80,
};

/**
 * @if Eng
 * @brief  NFC NCI logical connection identification.
 * @else
 * @brief  NFC NCI协议标准中逻辑管道的id值。
 * @endif
 */
enum NCI_LOGIC_CONN_ID_ENUM {
    /** @if Eng  Static RF connection.
     *  @else    静态射频逻辑管道。 @endif */
    NCI_STATIC_RF_CONN      = 0x00,
    /** @if Eng  Static HCI connection.
     *  @else    静态HCI逻辑管道。 @endif */
    NCI_STATIC_HCI_CONN     = 0x01,
};

/**
 * @if Eng
 * @brief  Card selection priority according to 1st device or specified protocol type of device. \n
 *         Except the first priority, any other priority value is equal to the related protocol value.
 * @else
 * @brief  选卡激活优先级，选择第一个卡片设备或者拥有某个具体协议类型的设备。除了第一个优先级以外，其他优先级值等于对应的协议值。
 * @endif
 */
enum NFC_CARD_SELECT_PRIORITY_ENUM {
    /** @if Eng  Priority to the first found card.
     *  @else    优先选择第一个发现的卡片设备。 @endif */
    PRIO_FIRST      = 0x00,
    /** @if Eng  Priority to the first T1T protocol card.
     *  @else    优先选择第一个T1T协议的卡片设备。 @endif */
    PRIO_T1T        = 0x01,
    /** @if Eng  Priority to the first T2T protocol card.
     *  @else    优先选择第一个T2T协议的卡片设备。 @endif */
    PRIO_T2T        = 0x02,
    /** @if Eng  Priority to the first T3T protocol card.
     *  @else    优先选择第一个T3T协议的卡片设备。 @endif */
    PRIO_T3T        = 0x03,
    /** @if Eng  Priority to the first ISO-DEP protocol card.
     *  @else    优先选择第一个ISO-DEP协议的卡片设备。 @endif */
    PRIO_ISODEP     = 0x04,
    /** @if Eng  Priority to the first NFC-DEP protocol card.
     *  @else    优先选择第一个NFC-DEP协议的卡片设备。 @endif */
    PRIO_NFCDEP     = 0x05,
    /** @if Eng  Priority to the first T5T protocol card.
     *  @else    优先选择第一个T5T协议的卡片设备。 @endif */
    PRIO_T5T        = 0x06,
    /** @if Eng  Invalid priority after all fixed or public protocol.
     *  @else    在固定或基于公开协议基础上的优先级之后的第一个无效的优先级值。 @endif */
    PRIO_PUBLIC_END = 0x07,
    /** @if Eng  Priority to the first proprietary protocol A card.
     *  @else    优先选择第一个私有协议A的卡片设备。 @endif */
    PRIO_PROP_A     = 0x80,
};

#ifdef __cplusplus
}
#endif

#endif // NFC_DEFS_H
/**
 * @}
 */
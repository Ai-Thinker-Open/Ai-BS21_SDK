/*
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved.
 * Description: slp at
 * ROM      : NO
 * STRATEGY : NO
 */

#ifndef SLP_AT_H
#define SLP_AT_H

#include <stdint.h>
#include "slp_factory.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint32_t paraMap;
    uint32_t usageMode;         // 使用模式，0-ranging_aoa，1-air_mouse
    uint32_t rangingMode;       // 测距、定位模式
    uint32_t aoxDirection;      // 测角方向，0-poll帧后单向测向，1-resp帧后单向测角，2-双向测角 */
    uint32_t mrSource;          // 测量值传递方向, 0-本机接收, 1-本机发送
    uint32_t roundNum;          // 有效的ranging rounds数量
    uint32_t rangingFreq;       // 测距频率, 1~255Hz
    uint32_t txMode;            // Tx发射模式, 0-不进入常发模式，1-启动Tx常发，2-关闭Tx常发
    uint32_t txPowerHigh;       // Tx功率码字高16bit, 包括LP通路下14~-5dBm芯片口发射功率, step为0.5dB
    uint32_t txPowerLow;        // Tx功率码字低16bit, 包括LP通路下14~-5dBm芯片口发射功率, step为0.5dB
} SlpAtSendRangingCtrlReqT;

typedef struct {
    uint32_t paraMap;  // paraMap是框架里需要的, 标识某一次发指令用了哪几个参数,
                       // 比如一共5个参数, 135可省略, paramap就是01010, 不需要设置，但是定义时候要加上。
    SlpPhaseCaliPara slpPhaseCaliPara;
} SlpAtCaliPara;

typedef struct {
    uint32_t paraMap;  // paraMap是框架里需要的, 标识某一次发指令用了哪几个参数,
                       // 比如一共5个参数, 135可省略, paramap就是01010, 不需要设置，但是定义时候要加上。
    uint32_t txPowerHigh;
    uint32_t txPowerLow;
} SlpAtTxPowerPara;

typedef struct {
    uint32_t paraMap;
    uint32_t timeDelay;
} SlpAtBoardAntTrxTimeDelayPara;

void SlpAtRegister(void);

#ifdef __cplusplus
}
#endif

#endif
#ifndef DISALG_H
#define DISALG_H

#include "generalPara.h"
#include "basicMath.h"
#include "KDE.h"

#define ALG_IQ_FLIP_BARRIER     1023
#define ALG_IQ_FLIP_OFFSET      2048

typedef enum {
    METHOD_1M = 1,
    METHOD_2M = 2,
    METHOD_1M_2M = 3,
    METHOD_ADJ_R_END = 4
} dis_alg_type;

typedef struct {
    unsigned short int i_data;
    unsigned short int q_data;
} alg_iq;
typedef struct {
    alg_iq *iq_dut;             // dut的iq数据
    alg_iq *iq_rtd;             // rtd的iq数据
    int rssi_dut;               // rtd信号的rssi
    int rssi_rtd;               // dut信号的rssi
    float calib_val;            // iq测距校准值
    para_pair para_limit;       // 测距算法参数配置，目前采用{-120，20，2}
    dis_alg_type flag_inter;    // 配置为4
    int tof_result;             // tof测距值
    int tof_calib;              // tof校准值
} para_dis_calc;

typedef struct {
    float dist_first;           // 第一测距值(当前使用)
    float dist_second;          // 第二测距值(备用，当前未使用)
    float dist_double;          // double平滑距值:实时性更高，波动相对更大
    float prob;                 // 置信度
    float rssi;                 // 信号强度
    float high;                 // 置信度相关系数
    int rssi_dut;               // dut的rssi
    int rssi_rtd;               // rtd的rssi
    unsigned char smooth_num;   // 有效平滑次数
} dis_result;

dis_result dist_calc(para_dis_calc *para_ec);
#endif
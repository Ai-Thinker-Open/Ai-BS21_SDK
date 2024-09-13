#ifndef ALG_SMOOTH_DIS_H
#define ALG_SMOOTH_DIS_H

#include "disalg.h"
#include "smooth.h"

#define ALG_CHANNEL_NUM         79
#define ALG_RSSI_OFFSET         256
#define ALG_RSSI_INVALID        (-128)

#define ALG_NUM_2               2
#define ALG_NUM_1000            1000

typedef struct {
    alg_iq *iq_dut;                     // dut的IQ数据
    alg_iq *iq_rtd;                     // rtd的IQ数据
    unsigned short int rssi_dut;        // dut的RSSI
    unsigned short int rssi_rtd;        // rtd的RSSI
    float calib_val;                    // IQ测距的校准值
    para_pair para_limit;               // 测距算法参数配置
    dis_alg_type flag_inter;            // 测距算法选择，配置为4
    unsigned int tof_rtd;               // rtd的ToF测距结果
    unsigned int tof_dut;               // dut的ToF测距结果
    int tof_calib;                      // ToF测距的校准准值
    para_keys_info keys_info;           // 钥匙信息
    unsigned int cur_count;             // 测距次数计数
    unsigned long long int cur_time;    // 当前测距时间
} alg_para_dis;

/* 测距算法参数配置
typedef struct {
    signed char rssi_limit;   // -120, RSSI小于该值时，测距结果为-1
    float threshold_cond2;    // 20
    unsigned char r_start;    // 2
} para_pair;
*/

/* 钥匙信息
typedef struct {
    int key_num;        // 当前数据为第n个钥匙
    int key_num_all;    // 总共有几个钥匙
} para_keys_info;
*/

/* 测距算法输出结果的dis_result结构体定义
typedef struct {
    float dist_first;    // 第一测距值(当前使用)
    float dist_second;   // 第二测距值(备用，当前未使用)
    float dist_double;   // double平滑距值:实时性更高，波动相对更大
    float prob;          // 置信度
    float rssi;          // 信号强度
    float high;          // 置信度相关系数
    int rssi_dut;        // dut的rssi
    int rssi_rtd;        // rtd的rssi
    unsigned char smooth_num;   // 有效平滑次数
} dis_result;
*/

dis_result slem_alg_calc_smoothed_dis(alg_para_dis *alg_para);

#endif
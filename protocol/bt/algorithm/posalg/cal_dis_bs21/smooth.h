#ifndef SMOOTH_H
#define SMOOTH_H

#include "basicMath.h"
// Smooth buff
enum {
    SMOOTH_LINK_A = 0,
    SMOOTH_LINK_B,
    SMOOTH_LINK_C,
    SMOOTH_LINK_D,
    SMOOTH_LINK_E,
    SMOOTH_POS_X,
    SMOOTH_POS_Y,
    SMOOTH_POS_Z,
    SMOOTH_BUFFER_BUTT = 1
};

typedef struct {
    int key_num;
    int key_num_all;
} para_keys_info;

typedef struct {
    int cur_count;
    unsigned int cur_time;
} para_cur_info;

typedef struct {
    float dist_first;
    float dist_second;
} cal_dis_res;

float smoothing_of_dis(unsigned char link, para_cur_info cur_info, cal_dis_res dis_res, int flag,
    para_keys_info keys_info);
float smoothing_of_prob(unsigned char link, para_cur_info cur_info, float prob, para_keys_info keys_info);
float smoothing_of_rssi(float rssi, para_keys_info keys_info);
float smoothing_of_high(float high, para_keys_info keys_info);
unsigned int smoothing_of_tof(unsigned int tof_result, para_keys_info keys_info);
float get_dis_double(unsigned char link, para_keys_info keys_info);
unsigned char get_smooth_num(unsigned char link, para_keys_info keys_info);
unsigned char get_min_smooth_num(void);
#endif
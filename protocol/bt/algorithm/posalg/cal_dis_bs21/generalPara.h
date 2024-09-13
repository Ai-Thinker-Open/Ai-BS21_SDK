#ifndef _GENERALPARA_H_
#define _GENERALPARA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "f2c.h"
#include "clapack.h"
#define PRINT_ALLOW 1
// for math

#define ERR_DIS_NUM -1
#define PI 3.14159265
#define NUM 500
#define EPS 1E-6
#define MOVE_BIT 11

// esprit1.2
#define SIG_DIS 1

#define N_FREQ_1M 79
#define N_SUB_1M 50
#define DIST_MAX_1M 150

#define N_FREQ_2M 39
#define N_SUB_2M 25
#define R_END_MOVE_INDEX 2
#define DIST_MAX_2M 75

#define USE_ALL_COND 0
#define Eigen_test 0

// for smooth

typedef struct {
    int index;
    float maxmin_num;   
} maxmin_idx_pair;
typedef struct {
    int key;
    float value;
} map_int_float;
typedef struct {
    float dis_first;
    float dis_second;
} dis_pair;
typedef struct {
    signed char rssi_limit;
    float threshold_cond2;
    unsigned char r_start;
} para_pair;
#endif

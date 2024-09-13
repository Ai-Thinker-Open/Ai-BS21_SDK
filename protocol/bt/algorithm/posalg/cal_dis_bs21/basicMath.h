#ifndef _BASICMATH_H_
#define _BASICMATH_H_

#include "generalPara.h"

static inline int sign(float x)
{
    return ((x >= 0) ? 1 : -1);
}

static inline complex mtcc(complex z1, complex z2)
{
    complex result = { z1.r * z2.r - z1.i * z2.i, z1.r * z2.i + z1.i * z2.r };
    return result;
}

static inline complex dcf(complex z1, float z2)
{
    complex result = { z1.r / z2, z1.i / z2 };
    return result;
}

static inline void dcmf(complex *a, float b, int n)
{
    for (int i = 0; i < n; i++) {
        a[i] = dcf(a[i], b);
    }
}

static inline complex pcc(complex z1, complex z2)
{
    complex result = { z1.r + z2.r, z1.i + z2.i };
    return result;
}

static inline void pcmm(complex *a, complex *b, int n)
{
    for (int i = 0; i < n; i++) {
        a[i] = pcc(a[i], b[i]);
    }
}

static inline float fast_sqrtf(float x)
{
    float xhalf = 0.5f * x;
    int i = *(int *)&x;             // get bits for floating value
    i = 0x5f375a86 - (i >> 1);      // gives initial guess y0
    x = *(float *)&i;               // convert bits back to float
    x = x * (1.5f - xhalf * x * x); // Newton step, repeating increases accuracy
    x = x * (1.5f - xhalf * x * x);
    x = x * (1.5f - xhalf * x * x);
    return 1 / x;
}

static inline float absc(complex z)
{
    return fast_sqrtf(z.r * z.r + z.i * z.i);
}

static inline float arg(complex z)
{
    float result = 0.0f;
    if (z.r > 0) {
        result = atan(z.i / z.r);
    } else if (z.r < 0) {
        result = atan(z.i / z.r) + sign(z.i) * PI;
    } else if (z.i == 0) {
        result = (float)0.0f;
    } else {
        result = sign(z.i) * PI / 2;
    }
    return result;
}

complex *mtcmcm_ed(complex *a, complex *b, int m, int n, int k, int r_end, int flag);
complex *conjdot_ed(complex *a, int n, int m, int r_end);
complex *dotconj_ss(complex *a, int n, int m, int flag, int r);
complex *inv_ed(complex *a, const int m, const int r_end);

// float
static inline int searchidx(map_int_float *p, int len, int search)
{
    for (int i = 0; i < len; i++) {
        if (p[i].key == search) {
            return i;
        }
    }
    return -1;
}

static inline maxmin_idx_pair findmin_idx(float *arr, int buffsize)
{
    maxmin_idx_pair result = { 0, arr[0] };
    for (int i = 1; i < buffsize; i++) {
        if (arr[i] < result.maxmin_num) {
            result.maxmin_num = arr[i];
            result.index = i;
        }
    }
    return result;
}

static inline maxmin_idx_pair findmax_idx(float *arr, int buffsize)
{
    maxmin_idx_pair result = { 0, arr[0] };
    for (int i = 1; i < buffsize; i++) {
        if (arr[i] > result.maxmin_num) {
            result.maxmin_num = arr[i];
            result.index = i;
        }
    }
    return result;
}

static inline void insertsort(float *arr, int n)
{
    int i, j;
    for (i = 1; i < n; i++) {
        float key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

static inline void insertsort_dict(map_int_float *arr, int n)
{
    int i, j;
    for (i = 1; i < n; i++) {
        map_int_float key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j].key > key.key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
#endif
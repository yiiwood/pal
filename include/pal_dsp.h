#pragma once

/*
 ****************************************************************
 * 1D: Filters, Convolution, Correlation Functions
 *
 * x,y          : input vector pointers
 * h            : input coefficient vector pointer
 * r            : output result vector pointer
 * dbuf         : delay buffer pointer
 * nx,ny,nr,nh  : size of respective vectors
 *
 ****************************************************************
 */

/*auto correlation: r[j] = sum ( x[j+k] * x[k] ), k=0..(n-j-1) */
void p_acorr_f32(float *x, int nx, float *r);

/*convolution: r[j] = sum ( h[k] * x[j-k), k=0..(nh-1) */
void p_conv_f32(float *x, float *h, int nx, int nh, float *r);

/*correlation: r[j] = sum ( x[j+k] * y[k]), k=0..(nx+ny-1) */
void p_xcorr_f32(float *x, float *y, int nx, int ny, float *r);

/*FIR filter direct form: r[j] = sum ( h[k] * x [j-k]), k=0..(nh-1) */
void p_fir_f32(float *x, float *h, float *dbuf, int nx, int nh, float *r);

/*FIR filter with decimation: r[j] = sum ( h[k] * x [j*D-k]), k=0..(nh-1) */
int p_firdec_f32(float *x, float *h, float *dbuf, int nx, int nh, int d,
                 float *r);

/*FIR filter with inerpolation: r[j] = sum ( h[k] * x [j*D-k]), k=0..(nh-1) */
void p_firint_f32(float *x, float *h, float *b, int nx, int nh, int ifactor,
                  float *r);

/*FIR symmetric form: */
void p_firsym_f32(float *x, float *h, float *dbuf, int nx, int nh, float *r);

/*IIR filter: */
void p_iir_f32(float *x, float *h, float *dbuf, int nx, int nh, float *r);

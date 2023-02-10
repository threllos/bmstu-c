#ifndef _VARIANCE_H_
#define _VARIANCE_H_

#include <stdio.h>

double calc_avg(FILE *f, int *count);
double calc_variance(FILE *f, double avg, int count);

#endif
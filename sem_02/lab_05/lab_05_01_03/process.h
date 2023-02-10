#ifndef _PROCESS_H_
#define _PROCESS_H_

#include <stdio.h>

int process(FILE *f, int *result);
int is_sign_changed(int prev, int curr);

#endif
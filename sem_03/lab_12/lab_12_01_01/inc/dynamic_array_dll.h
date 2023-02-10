#ifndef _DYNAMIC_ARRAY_H_
#define _DYNAMIC_ARRAY_H_

#ifdef ARR_EXPORTS
#define ARR_DLL __declspec(dllexport)
#else
#define ARR_DLL __declspec(dllimport)
#endif

#define ARR_DECL __cdecl

#include <stdlib.h>
#include <stdio.h> 

ARR_DLL int ARR_DECL count_len(FILE *f, size_t *len);
ARR_DLL int ARR_DECL read_array(FILE *f, const int *pb_array, const int *pe_array);
ARR_DLL int ARR_DECL key_len(const int *pb_src, const int *pe_src, size_t *len);
ARR_DLL int ARR_DECL key(const int *pb_src, const int *pe_src, int *pb_dst);
ARR_DLL int ARR_DECL compare(const void *x1, const void *x2);
ARR_DLL void ARR_DECL mysort(void *base, size_t nmemb, size_t size, int (*compare)(const void *, const void *));
ARR_DLL int ARR_DECL write_array(FILE *f, const int *pb_array, const int *pe_array);

#endif

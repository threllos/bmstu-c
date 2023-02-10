#ifndef _ARRAY_H_
#define _ARRAY_H_

#ifdef ARRAY_EXPORTS
#define ARRAY_DLL __declspec(dllexport)
#else
#define ARRAY_DLL __declspec(dllimport)
#endif

#define ARRAY_DECL __cdecl

#define FAILURE 1
#define SUCCESS 0

ARRAY_DLL int ARRAY_DECL fibonacci_fill(int *array, int size);
ARRAY_DLL void ARRAY_DECL filter(int *src, int src_size, int *dst, int *dst_size);

#endif // _ARRAY_H_
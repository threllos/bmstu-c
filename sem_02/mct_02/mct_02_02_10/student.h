#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#define MAX_LEN 126

#pragma pack(push, 1)
typedef struct
{
    char sname[MAX_LEN];
    int64_t n;
} student_t;
#pragma pack(pop)

#define SIZE sizeof(student_t)

int get_size(FILE *f, size_t *size);
size_t get_len(size_t size_file);
int get_student_by_pos(FILE *f, size_t pos, student_t *student);
int put_student_by_pos(FILE *f, size_t pos, student_t *student);

int del_students(FILE *src);

#endif
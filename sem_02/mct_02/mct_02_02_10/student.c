#include <string.h>
#include "student.h"

int get_size(FILE *f, size_t *size)
{
    int sz;
    
    if (fseek(f, 0, SEEK_END))
        return EXIT_FAILURE;
    
    sz = ftell(f);
    if (sz < 0)
        return EXIT_FAILURE;
    
    *size = sz;
    
    return fseek(f, 0, SEEK_SET);
}

size_t get_len(size_t size_file)
{
    return size_file / SIZE;
}

int get_student_by_pos(FILE *f, size_t pos, student_t *student)
{
    if (fseek(f, pos * SIZE, SEEK_SET))
        return EXIT_FAILURE;
    
    if (fread(student, SIZE, 1, f) != 1)
        return EXIT_FAILURE;
    
    return fseek(f, 0, SEEK_SET);
}

int put_student_by_pos(FILE *f, size_t pos, student_t *student)
{
    if (fseek(f, pos * SIZE, SEEK_SET))
        return EXIT_FAILURE;
    
    if (fwrite(student, SIZE, 1, f) != 1)
        return EXIT_FAILURE;
    
    return fseek(f, 0, SEEK_SET);
}

int del_students(FILE *src)
{
    size_t size;
    
    if (get_size(src, &size))
        return EXIT_FAILURE;
    
    if (size % SIZE != 0)
        return EXIT_FAILURE;
    
    size_t len = get_len(size);
    
    if (len == 0)
        return EXIT_FAILURE;
    
    size_t dst_pos = 0;
    for (size_t src_pos = 0; src_pos < len; src_pos++)
    {
        student_t student = { 0 };
        get_student_by_pos(src, src_pos, &student);
        
        if (strcmp(student.sname, "Ivanov") >= 0 &&
        strcmp(student.sname, "Petrov") <= 0)
            put_student_by_pos(src, dst_pos++, &student);
    }
    
    if (dst_pos == 0)
        return EXIT_FAILURE;
    
    student_t student = {0};
    strcpy(student.sname, "0000");
    while (dst_pos < len)
        put_student_by_pos(src, dst_pos++, &student);
        
    return EXIT_SUCCESS;
}